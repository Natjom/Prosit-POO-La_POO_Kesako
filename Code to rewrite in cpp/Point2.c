#include "Point2.h"

void Point2_init(Point2 *p) {
    p->x = 0;
    p->y = 0;
}

void Point2_init_with_xy(Point2 *p, float x, float y) {
    p->x = x;
    p->y = y;
}

float Point2_getX(const Point2 *p) {
    return p->x;
}

float Point2_getY(const Point2 *p) {
    return p->y;
}

void Point2_setX(Point2 *p, float x) {
    p->x = x;
}

void Point2_setY(Point2 *p, float y) {
    p->y = y;
}

void Point2_print(const Point2 *p) {
    printf("{%f, %f}\n", p->x, p->y);
}

Vector2 Point2_sub(Point2 *r, const Point2 *p) {
    Vector2 result;
    
    result.x = r->x - p->x;
    result.y = r->y - p->y;
    
    return result;
}

Point2 Point2_add(const Point2 *p, const Vector2 *r) {
    Point2 result;
    
    result.x = p->x + r->x;
    result.y = p->y + r->y;
    
    return result;
}