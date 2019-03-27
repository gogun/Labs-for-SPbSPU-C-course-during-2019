#ifndef CN_A2_BASETYPES
#define CN_A2_BASETYPES

namespace chizhov
{
  struct point_t {
    double x;
    double y;
  };

  struct rectangle_t {
    double width;
    double height;
    point_t pos;
  };
}
#endif
