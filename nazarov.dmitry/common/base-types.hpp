#ifndef BASE_TYPESS_HPP_INCLUDED
#define BASE_TYPESS_HPP_INCLUDED

namespace nazarov
{
  struct point_t
  {
    double x, y;
  };
  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
}
#endif
