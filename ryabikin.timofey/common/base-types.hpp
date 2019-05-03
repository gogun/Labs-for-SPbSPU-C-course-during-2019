#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace ryabikin
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double height;
    double width;
    point_t pos;
  };
}
#endif
