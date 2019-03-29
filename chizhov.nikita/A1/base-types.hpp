#ifndef CN_A1_BASETYPES
#define CN_A1_BASETYPES

struct point_t {
  double x;
  double y;
};

struct rectangle_t {
  double width;
  double height;
  point_t pos;
};
#endif
