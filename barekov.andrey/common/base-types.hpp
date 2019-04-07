#ifndef A2_BASE_TYPES
#define A2_BASE_TYPES

namespace barekov
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}

#endif
