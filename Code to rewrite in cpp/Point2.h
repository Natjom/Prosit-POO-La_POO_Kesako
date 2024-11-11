#ifndef POINT2_H
#define POINT2_H

#include "Vector2.h"
#include <stdio.h>

typedef struct {
    float x, y;
} Point2;

void Point2_init(Point2 *p);
void Point2_init_with_xy(Point2 *p, float x, float y);
float Point2_getX(const Point2 *p);
float Point2_getY(const Point2 *p);
void Point2_setX(Point2 *p, float x);
void Point2_setY(Point2 *p, float y);
void Point2_print(const Point2 *p);

#endif // POINT2_H