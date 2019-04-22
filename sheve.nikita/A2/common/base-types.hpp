#ifndef BASETYPES_HPP
#define BASETYPES_HPP

namespace sheve
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
