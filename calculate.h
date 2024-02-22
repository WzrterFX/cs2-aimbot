#ifndef CALCULATE_H
#define CALCULATE_H

#include "include.h"

Vector2 screen = Vector2(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

inline Vector2 CalculateAngles(Vector3 from, Vector3 to)
{
    float yaw;
    float pitch;

    float deltaX = to.x - from.x;
    float deltaY = to.y - from.y;
    float deltaZ = to.z - from.z;

    double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    yaw = atan2(deltaY, deltaX) * 180 / 3.14;
    pitch = -(atan2(deltaZ, distance) * 180 / 3.14);

    return Vector2(yaw, pitch);
}

inline Vector2 WorldToScreen(ViewMatrix matrix, Vector3 position, Vector2 screen)
{
    float screenW = (matrix.m41 * position.x) + (matrix.m42 * position.y) + (matrix.m43 * position.z) + matrix.m44;

    if (screenW > 0.1)
    {
        float screenX = (matrix.m11 * position.x) + (matrix.m12 * position.y) + (matrix.m13 * position.z) + matrix.m14;
        float screenY = (matrix.m21 * position.x) + (matrix.m22 * position.y) + (matrix.m23 * position.z) + matrix.m24;

        float x = (screen.x / 2) + (screen.x / 2) * screenX / screenW;
        float y = (screen.y / 2) - (screen.y / 2) * screenY / screenW;

        return Vector2(x, y);
    }
    else
        return Vector2(0, 0);
}

#endif