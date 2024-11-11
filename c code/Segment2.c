#include "Segment2.h"

void Segment2_init(Segment2 *s, Point2 origin, Vector2 direction) {
    s->origin = origin;
    s->direction = direction;
}

Point2 Segment2_getOrigin(const Segment2 *s) {
    return s->origin;
}

Vector2 Segment2_getDirection(const Segment2 *s) {
    return s->direction;
}

float Segment2_length(const Segment2 *s) {
    return Vector2_norm(&s->direction);
}

IntersectionStatus Segment2_intersect(const Segment2 *s, const Segment2 *r, Point2 *p) {
    Point2 oa = Segment2_getOrigin(s), ob = Segment2_getOrigin(r);
    Vector2 da = Segment2_getDirection(s), db = Segment2_getDirection(r);
    Vector2 dc = Point2_sub(&ob, &oa);

    IntersectionStatus status;
    float det = Vector2_cross(&da, &db);
    if (det != 0.0) {
        float u, v;

        u = Vector2_cross(&dc, &db) / det;
        v = Vector2_cross(&dc, &da) / det;
        if ((u >= 0.0 && u <= 1.0) && (v >= 0.0 && v <= 1.0)) {
            Vector2 tmp = Vector2_dot_scalar(&da, u);
            *p = Point2_add(&oa, &tmp);
            status = POINT;
        } else {
            status = NON_INTERSECTING;
        }
    } else {
        float st = Vector2_cross(&dc, &da);
        if (det == 0.0 && st == 0.0) { // check for collinearity
            float pj, d1, d2;

            pj = Vector2_dot(&da, &da);
            d1 = Vector2_dot(&dc, &da) / pj;
            d2 = d1 + Vector2_dot(&db, &da) / pj;

            if (d1 >= 0.0 && d1 <= 1.0) {
                *p = ob;
                status = COLINEAR_INTERSECTING;
            } else if (d2 >= 0.0 && d2 <= 1.0) {
                Point2 tmp_ob_db = Point2_add(&ob, &db);
                *p = tmp_ob_db;
                status = COLINEAR_INTERSECTING;
            } else {
                status = COLINEAR_NON_INTERSECTING;
            }
        } else if (det == 0.0 && st != 0.0) {
            status = PARALLEL_NON_INTERSECTING;
        }
    }

    return status;
}