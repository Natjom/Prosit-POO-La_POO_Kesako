#include <stdio.h>
#include <stdlib.h>

#include "Point2.h"
#include "Vector2.h"
#include "Segment2.h"

int main(void) {
  Point2 p1, p2;
  Vector2 v1, v2;
  Segment2 s1, s2;

  Point2_init_with_xy(&p1, 0., 0.);
  Point2_init_with_xy(&p2, 1., 2.);

  Vector2_init(&v1, 1., 1.);
  Vector2_init(&v2, 2., 4.);
  
  Segment2_init(&s1, p1, v1);
  Segment2_init(&s2, p2, v2);

  
  return EXIT_SUCCESS;
}