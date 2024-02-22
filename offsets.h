#ifndef OFFSETS_H
#define OFFSETS_H

#include "include.h"

inline Wmemory cs2(L"cs2.exe");

namespace Offsets
{
	adr64 client = cs2.GetModuleBaseAddress(L"client.dll");

	adr64 dwLocalPlayerPawn = 0x1729348;
	adr64 dwEntityList = 0x18B3FA8;
	adr64 dwViewAngles = 0x19233E0;
	adr64 dwViewMatrix = 0x19154C0;

	adr32 m_vOldOrigin = 0x127C;
	adr32 m_vecViewOffset = 0xC58;
	adr32 m_iTeamNum = 0x3CB;
	adr32 m_hPlayerPawn = 0x7E4;
	adr32 m_pGameSceneNode = 0x318;
	adr32 m_modelState = 0x160;
	adr32 m_iHealth = 0x334;
	adr32 m_lifeState = 0x338;
	adr32 m_entitySpottedState = 0x1698;
	adr32 m_bSpotted = 0x8;
}

#endif