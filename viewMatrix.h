#ifndef VIEW_MATRIX_H
#define VIEW_MATRIX_H

#include "offsets.h"

struct ViewMatrix
{
    float m11, m12, m13, m14;
    float m21, m22, m23, m24;
    float m31, m32, m33, m34;
    float m41, m42, m43, m44;
};

inline ViewMatrix ReadMatrix(uptr64 address)
{
    ViewMatrix viewMatrix;

    ViewMatrix matrix = cs2.ReadMemory<ViewMatrix>(address);

    viewMatrix.m11 = matrix.m11;
    viewMatrix.m12 = matrix.m12;
    viewMatrix.m13 = matrix.m13;
    viewMatrix.m14 = matrix.m14;

    viewMatrix.m21 = matrix.m21;
    viewMatrix.m22 = matrix.m22;
    viewMatrix.m23 = matrix.m23;
    viewMatrix.m24 = matrix.m24;

    viewMatrix.m31 = matrix.m31;
    viewMatrix.m32 = matrix.m32;
    viewMatrix.m33 = matrix.m33;
    viewMatrix.m34 = matrix.m34;

    viewMatrix.m41 = matrix.m41;
    viewMatrix.m42 = matrix.m42;
    viewMatrix.m43 = matrix.m43;
    viewMatrix.m44 = matrix.m44;

    return viewMatrix;
}

#endif