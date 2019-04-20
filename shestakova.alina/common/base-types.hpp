#ifndef A1_BASE_TYPES_HPP
#define A1_BASE_TYPES_HPP

namespace shestakova
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
