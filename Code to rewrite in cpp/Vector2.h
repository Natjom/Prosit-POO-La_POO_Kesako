#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>


typedef struct {
    float x, y;
} Vector2;

void Vector2_init(Vector2 *v, float x, float y);
float Vector2_getX(const Vector2 *v);
float Vector2_getY(const Vector2 *v);
float Vector2_norm(const Vector2 *v);
float Vector2_dot(const Vector2 *v, const Vector2 *r);
Vector2 Vector2_dot_scalar(const Vector2 *v, float u);
float Vector2_cross(const Vector2 *v, const Vector2 *r);
Vector2 Vector2_negate(const Vector2 *v);

#endif // VECTOR2_H