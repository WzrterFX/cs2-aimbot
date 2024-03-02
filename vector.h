#ifndef VECTOR_H
#define VECTOR_H

#include "math.h"

/// <summary>
/// structure representing a vector with x, y components.
/// </summary>
struct Vector2
{
    float x, y;

    /// <summary>
    // addition operator
    /// </summary>
    Vector2 operator+(const Vector2& other) const
    {
        return { x + other.x, y + other.y };
    }

    /// <summary>
    // subtraction operator
    /// </summary>
    Vector2 operator-(const Vector2& other) const
    {
        return { x - other.x, y - other.y };
    }

    /// <summary>
    // multiplication operator
    /// </summary>
    Vector2 operator*(const Vector2& other) const
    {
        return { x * other.x, y * other.y };
    }

    /// <summary>
    // division operator
    /// </summary>
    Vector2 operator/(const Vector2& other) const
    {
        return { x / other.x, y / other.y };
    }

    /// <summary>
    // equality operator
    /// </summary>
    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    /// <summary>
    // method to calculate distance between two points
    /// </summary>
    static float Distance(const Vector2& first, const Vector2& second)
    {
        return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
    }

    /// <summary>
    // method to perform linear interpolation between two points
    /// </summary>
    static Vector2 Lerp(const Vector2& first, const Vector2& second, float time)
    {
        return Vector2(first.x + time * (second.x - first.x), first.y + time * (second.y - first.y));
    }

    /// <summary>
    // constructor
    /// </summary>
    Vector2(float _x, float _y) : x(_x), y(_y) { }

    /// <summary>
    // default constructor
    /// </summary>
    Vector2() : x(0), y(0) { }
};

/// <summary>
/// structure representing a vector with x, y, z components.
/// </summary>
struct Vector3
{
    float x, y, z;

    /// <summary>
    // addition operator
    /// </summary>
    Vector3 operator+(const Vector3& other) const
    {
        return { x + other.x, y + other.y, z + other.z };
    }

    Vector3 operator+(const Vector2& other) const
    {
        return { x + other.x, y + other.y, z };
    }

    /// <summary>
    // subtraction operator
    /// </summary>
    Vector3 operator-(const Vector3& other) const
    {
        return { x - other.x, y - other.y, z - other.z };
    }

    Vector3 operator-(const Vector2& other) const
    {
        return { x - other.x, y - other.y, z };
    }

    /// <summary>
    // multiplication operator
    /// </summary>
    Vector3 operator*(const Vector3& other) const
    {
        return { x * other.x, y * other.y, z * other.z };
    }

    Vector3 operator*(const Vector2& other) const
    {
        return { x * other.x, y * other.y, z };
    }

    /// <summary>
    // division operator
    /// </summary>
    Vector3 operator/(const Vector3& other) const
    {
        return { x / other.x, y / other.y, z / other.z };
    }

    Vector3 operator/(const Vector2& other) const
    {
        return { x / other.x, y / other.y, z };
    }

    /// <summary>
    // equality operator
    /// </summary>
    bool operator==(const Vector3& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    /// <summary>
    // method to calculate distance between two points
    /// </summary>
    static float Distance(const Vector3& first, const Vector3& second)
    {
        return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2));
    }

    /// <summary>
    // method to perform linear interpolation between two points
    /// </summary>
    static Vector3 Lerp(const Vector3& first, const Vector3& second, float time)
    {
        return Vector3(first.x + time * (second.x - first.x), first.y + time * (second.y - first.y), first.z + time * (second.z - first.z));
    }

    /// <summary>
    // constructor
    /// </summary>
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

    /// <summary>
    // default constructor
    /// </summary>
    Vector3() : x(0), y(0), z(0) { }
};

/// <summary>
/// structure representing a vector with x, y, z, w components.
/// </summary>
struct Vector4
{
    float x, y, z, w;

    /// <summary>
    // addition operator
    /// </summary>
    Vector4 operator+(const Vector4& other) const
    {
        return { x + other.x, y + other.y, z + other.z, w + other.w };
    }

    Vector4 operator+(const Vector2& other) const
    {
        return { x + other.x, y + other.y, z, w };
    }

    Vector4 operator+(const Vector3& other) const
    {
        return { x + other.x, y + other.y, z + other.z, w };
    }

    /// <summary>
    // subtraction operator
    /// </summary>
    Vector4 operator-(const Vector4& other) const
    {
        return { x - other.x, y - other.y, z - other.z, w - other.w };
    }

    Vector4 operator-(const Vector2& other) const
    {
        return { x - other.x, y - other.y, z, w };
    }

    Vector4 operator-(const Vector3& other) const
    {
        return { x - other.x, y - other.y, z - other.z, w };
    }

    /// <summary>
    // multiplication operator
    /// </summary>
    Vector4 operator*(const Vector4& other) const
    {
        return { x * other.x, y * other.y, z * other.z, w * other.w };
    }

    Vector4 operator*(const Vector2& other) const
    {
        return { x * other.x, y * other.y, z, w };
    }

    Vector4 operator*(const Vector3& other) const
    {
        return { x * other.x, y * other.y, z * other.z, w };
    }

    /// <summary>
    // division operator
    /// </summary>
    Vector4 operator/(const Vector4& other) const
    {
        return { x / other.x, y / other.y, z / other.z, w / other.w };
    }

    Vector4 operator/(const Vector2& other) const
    {
        return { x / other.x, y / other.y, z, w };
    }

    Vector4 operator/(const Vector3& other) const
    {
        return { x / other.x, y / other.y, z / other.z, w };
    }

    /// <summary>
    // equality operator
    /// </summary>
    bool operator==(const Vector4& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    /// <summary>
    // method to calculate distance between two points
    /// </summary>
    static float Distance(const Vector4& first, const Vector4& second)
    {
        return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2) + pow(first.w - second.w, 2));
    }

    /// <summary>
    // method to perform linear interpolation between two points
    /// </summary>
    static Vector4 Lerp(const Vector4& first, const Vector4& second, float time)
    {
        return Vector4(first.x + time * (second.x - first.x), first.y + time * (second.y - first.y), first.z + time * (second.z - first.z), first.w + time * (second.w - first.w));
    }

    /// <summary>
    // constructor
    /// </summary>
    Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) { }

    /// <summary>
    // default constructor
    /// </summary>
    Vector4() : x(0), y(0), z(0), w(0) { }
};

#endif