#ifndef BASETYPES_HPP
#define BASETYPES_HPP

namespace zakharova
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

#endif // BASETYPES_HPP
