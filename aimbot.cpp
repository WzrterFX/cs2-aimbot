#include "include.h"

float smoothness = 0.995;
uptr32 radius = 512;
bool spotted = true;

int main()
{
	vector<Entity> entities;
	Entity localPlayer;

	while (true)
	{
		entities.clear();

		localPlayer.pawnAddress = cs2.ReadMemory<uptr64>(Offsets::client + Offsets::dwLocalPlayerPawn);
		localPlayer.origin = cs2.ReadMemory<Vector3>(localPlayer.pawnAddress + Offsets::m_vOldOrigin);
		localPlayer.view = cs2.ReadMemory<Vector3>(localPlayer.pawnAddress + Offsets::m_vecViewOffset);
		localPlayer.team = cs2.ReadMemory<sptr32>(localPlayer.pawnAddress + Offsets::m_iTeamNum);

		uptr64 entityList = cs2.ReadMemory<uptr64>(Offsets::client + Offsets::dwEntityList);
		if (entityList == NULL)
			continue;

		uptr64 listEntry = cs2.ReadMemory<uptr64>(entityList + 0x10);

        for (int i = 0; i < 64; i++)
        {
            uptr64 currentController = cs2.ReadMemory<uptr64>(listEntry + i * 0x78);
            if (currentController == NULL)
                continue;

            uptr32 pawnHandle = cs2.ReadMemory<uptr32>(currentController + Offsets::m_hPlayerPawn);
            if (pawnHandle == NULL)
                continue;

            uptr64 listEntry2 = cs2.ReadMemory<uptr64>(entityList + 0x8 * ((pawnHandle & 0x7FFF) >> 9) + 0x10);

            uptr64 currentPawn = cs2.ReadMemory<uptr64>(listEntry2 + 0x78 * (pawnHandle & 0x1FF));
            if (currentPawn == localPlayer.pawnAddress)
                continue;

            uptr64 sceneNode = cs2.ReadMemory<uptr64>(currentPawn + Offsets::m_pGameSceneNode);
            uptr64 boneMatrix = cs2.ReadMemory<uptr64>(sceneNode + Offsets::m_modelState + 0x80);

            sptr32 team = cs2.ReadMemory<sptr32>(currentPawn + Offsets::m_iTeamNum);
            if (team == localPlayer.team)
                continue;

            sptr32 health = cs2.ReadMemory<sptr32>(currentPawn + Offsets::m_iHealth);

            uptr32 lifeState = cs2.ReadMemory<uptr32>(currentPawn + Offsets::m_lifeState);
            if (lifeState != 256)
                continue;

            ViewMatrix viewMatrix = ReadMatrix(Offsets::client + Offsets::dwViewMatrix);

            Entity entity;

            entity.pawnAddress = currentPawn;
            entity.controllerAddress = currentController;

            entity.origin = cs2.ReadMemory<Vector3>(currentPawn + Offsets::m_vOldOrigin);
            entity.view = cs2.ReadMemory<Vector3>(currentPawn + Offsets::m_vecViewOffset);
            entity.head = cs2.ReadMemory<Vector3>(boneMatrix + 6 * 32);
            entity.headScreen = WorldToScreen(viewMatrix, entity.head, screen);
            entity.crosshairDistance = Vector2::Distance(entity.headScreen, Vector2(screen.x / 2, screen.y / 2));
            entity.spoted = cs2.ReadMemory<bool>(currentPawn + Offsets::m_entitySpottedState + Offsets::m_bSpotted);
            if (!entity.spoted && spotted)
                continue;

            entity.health = health;
            entity.lifeState = lifeState;

            entities.push_back(entity);
        }

        sort(entities.begin(), entities.end(), [](const Entity& a, const Entity& b) { return a.crosshairDistance < b.crosshairDistance; });

        if (!entities.empty())
        {
            Vector3 currentAngles = cs2.ReadMemory<Vector3>(Offsets::client + Offsets::dwViewAngles);

            Vector2 angles = CalculateAngles(localPlayer.origin + localPlayer.view, entities[0].head);
            Vector3 target = Vector3(angles.y, angles.x, 0);

            if (entities[0].crosshairDistance < radius)
            {
                Vector3 interpolatedAngles = Vector3::Lerp(currentAngles, target, 1 - smoothness);

                cs2.WriteMemory<Vector3>(Offsets::client + Offsets::dwViewAngles, interpolatedAngles);
            }
        }
	}

	return 0;
}