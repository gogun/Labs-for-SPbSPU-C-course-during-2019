#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace afanasiev
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

} //namespace afanasiev

#endif //BASE_TYPES_HPP
