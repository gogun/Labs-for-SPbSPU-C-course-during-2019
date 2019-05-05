#ifndef BASE_TYPESS_HPP_INCLUDED
#define BASE_TYPESS_HPP_INCLUDED

namespace nazarov
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
#endif
