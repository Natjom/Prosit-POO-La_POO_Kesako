#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

typedef enum
{
    POINT,
    COLINEAR_INTERSECTING,
    COLINEAR_NON_INTERSECTING,
    PARALLEL_NON_INTERSECTING,
    NON_INTERSECTING
} IntersectionStatus;

class Vector2;

class Point2
{
public:
    float x;
    float y;

    Point2() : x(0), y(0) {}
    Point2(float x, float y) : x(x), y(y) {}
    Point2(Point2 *p) : x(p->x), y(p->y) {}
    ~Point2() {}

    float getX() { return x; }
    float getY() { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void afficher() { cout << "x = " << x << ", y = " << y << endl; }

    Point2 add(Vector2 p);
    Vector2 sub(Point2 p);
};

class Vector2
{
public:
    float x;
    float y;

    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2(Vector2 *v) : x(v->x), y(v->y) {}
    ~Vector2() {}

    float getX() { return x; }
    float getY() { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    float norm() { return sqrt(x * x + y * y); }
    float dot(Vector2 r) { return x * r.x + y * r.y; }
    Vector2 dot_scalar(float u) { return Vector2(x * u, y * u); }
    float cross(Vector2 r) { return (x * r.y) - (y * r.x); }
    Vector2 negate() { return Vector2(-x, -y); }
};

Point2 Point2::add(Vector2 p) { return Point2(this->x + p.x, this->y + p.y); }
Vector2 Point2::sub(Point2 p) { return Vector2(this->x - p.x, this->y - p.y); }

class Segment2
{
public:
    Point2 origin;
    Vector2 direction;

    Segment2() : origin(Point2(0, 0)), direction(Vector2(0, 0)) {}
    Segment2(Point2 origin, Vector2 direction) : origin(origin), direction(direction) {}
    Segment2(Segment2 *s) : origin(s->origin), direction(s->direction) {}
    ~Segment2() {}

    Point2 getOrigin() { return origin; }
    Vector2 getDirection() { return direction; }
    float Length() { return direction.norm(); }

    IntersectionStatus intersect(Segment2 r, Point2 p)
    {
        Point2 oa = this->getOrigin();
        Point2 ob = r.getOrigin();

        Vector2 da = this->getDirection();
        Vector2 db = r.getDirection();

        Vector2 dc = ob.sub(oa);

        IntersectionStatus status;
        float det = da.cross(db);
        if (det != 0.0)
        {
            float u, v;

            u = dc.cross(db) / det;
            v = dc.cross(da) / det;
            if ((u >= 0.0 && u <= 1.0) && (v >= 0.0 && v <= 1.0))
            {
                origin = oa.add(da.dot_scalar(u));
                status = POINT;
            }
            else
            {
                status = NON_INTERSECTING;
            }
        }
        else
        {
            float st = dc.cross(da);
            if (det == 0.0 && st == 0.0)
            { // check for collinearity
                float pj, d1, d2;

                pj = da.dot(da);
                d1 = dc.dot(da) / pj;
                d2 = d1 + db.dot(da) / pj;

                if (d1 >= 0.0 && d1 <= 1.0)
                {
                    origin = ob;
                    status = COLINEAR_INTERSECTING;
                }
                else if (d2 >= 0.0 && d2 <= 1.0)
                {
                    origin = ob.add(db);
                    status = COLINEAR_INTERSECTING;
                }
                else
                {
                    status = COLINEAR_NON_INTERSECTING;
                }
            }
            else if (det == 0.0 && st != 0.0)
            {
                status = PARALLEL_NON_INTERSECTING;
            }
        }
        return status;
    }
};

int main(void)
{
    Point2 p1(0., 0.);
    Point2 p2(1., 2.);
    Vector2 v1(1., 1.);
    Vector2 v2(2., 4.);
    Segment2 s1(p1, v1);
    Segment2 s2(p2, v2);

    cout << s1.intersect(s2, p1) << endl;
    return 1;
}
