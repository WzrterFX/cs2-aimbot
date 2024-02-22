#ifndef VECTOR_H
#define VECTOR_H

#include "math.h"

struct Vector2
{
    float x, y;

    Vector2 operator+(const Vector2& other) const
    {
        return { x + other.x, y + other.y };
    }

    Vector2 operator-(const Vector2& other) const
    {
        return { x - other.x, y - other.y };
    }

    Vector2 operator*(const Vector2& other) const
    {
        return { x * other.x, y * other.y };
    }

    Vector2 operator/(const Vector2& other) const
    {
        return { x / other.x, y / other.y };
    }

    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    static float Distance(const Vector2& first, const Vector2& second)
    {
        return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
    }

    static Vector2 Lerp(const Vector2& first, const Vector2& second, float time)
    {
        return Vector2(first.x + time * (second.x - first.x), first.y + time * (second.y - first.y));
    }

    Vector2(float _x, float _y) : x(_x), y(_y) { }

    Vector2() : x(0), y(0) { }
};

struct Vector3
{
    float x, y, z;

    Vector3 operator+(const Vector3& other) const
    {
        return { x + other.x, y + other.y, z + other.z };
    }

    Vector3 operator-(const Vector3& other) const
    {
        return { x - other.x, y - other.y, z - other.z };
    }

    Vector3 operator*(const Vector3& other) const
    {
        return { x * other.x, y * other.y, z * other.z };
    }

    Vector3 operator/(const Vector3& other) const
    {
        return { x / other.x, y / other.y, z / other.z };
    }

    bool operator==(const Vector3& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    static float Distance(const Vector3& first, const Vector3& second)
    {
        return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2));
    }

    static Vector3 Lerp(const Vector3& first, const Vector3& second, float time)
    {
        return Vector3(first.x + time * (second.x - first.x), first.y + time * (second.y - first.y), first.z + time * (second.z - first.z));
    }

    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

    Vector3() : x(0), y(0), z(0) { }
};

struct Vector4
{
    float x, y, z, w;

    Vector4 operator+(const Vector4& other) const
    {
        return { x + other.x, y + other.y, z + other.z, w + other.w };
    }

    Vector4 operator-(const Vector4& other) const
    {
        return { x - other.x, y - other.y, z - other.z, w - other.w };
    }

    Vector4 operator*(const Vector4& other) const
    {
        return { x * other.x, y * other.y, z * other.z, w * other.w };
    }

    Vector4 operator/(const Vector4& other) const
    {
        return { x / other.x, y / other.y, z / other.z, w / other.w };
    }

    bool operator==(const Vector4& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    static float Distance(const Vector4& first, const Vector4& second)
    {
        return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2) + pow(first.w - second.w, 2));
    }

    static Vector4 Lerp(const Vector4& first, const Vector4& second, float time)
    {
        return Vector4(first.x + time * (second.x - first.x), first.y + time * (second.y - first.y), first.z + time * (second.z - first.z), first.w + time * (second.w - first.w));
    }

    Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) { }

    Vector4() : x(0), y(0), z(0), w(0) { }
};

#endif