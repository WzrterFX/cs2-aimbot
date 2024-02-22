#ifndef ENTITY_H
#define ENTITY_H

#include "include.h"

struct Entity
{
    uptr64 pawnAddress;
    uptr64 controllerAddress;

    Vector3 origin;
    Vector2 originScreen;
    Vector3 view;
    Vector3 head;
    Vector2 headScreen;
    float crosshairDistance;
    bool spoted;

    sptr32 team;
    sptr32 health;
    uptr32 lifeState;

    Entity() : pawnAddress(NULL), controllerAddress(NULL), origin(Vector3()), originScreen(Vector2()), view(Vector3()), head(Vector3()), headScreen(Vector2()), crosshairDistance(0.0), spoted(true), team(0), health(0), lifeState(0) { }
};

#endif