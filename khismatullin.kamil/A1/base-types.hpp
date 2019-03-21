#ifndef BASE_TYPES
#define BASE_TYPES

struct point_t {
  double x;
  double y;
};

struct rectangle_t {
  point_t pos;
  double width;
  double height;
};

#endif
