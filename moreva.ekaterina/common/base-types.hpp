#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace moreva
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width, height;
    point_t pos;
  };
}

#endif //BASE_TYPES_HPP
