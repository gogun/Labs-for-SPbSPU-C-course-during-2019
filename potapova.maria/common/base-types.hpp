#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace potapova
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t pos;
    double height;
    double width;
  };
}

#endif // BASETYPES_HPP
