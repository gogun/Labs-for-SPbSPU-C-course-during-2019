#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace uzhegov
{
  struct point_t
  {
    double x, y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width, height;
  };
}
#endif
