#ifndef A2_BASE_TYPES_HPP_
#define A2_BASE_TYPES_HPP_

namespace korshunov
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
}

#endif
