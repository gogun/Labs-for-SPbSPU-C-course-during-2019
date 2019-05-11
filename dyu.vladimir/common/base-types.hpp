// header guard

#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace dyu
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


#endif /* BASE_TYPES_HPP */