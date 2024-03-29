#ifndef A1_BASE_TYPES_HPP
#define A1_BASE_TYPES_HPP

namespace nurtdinov
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
#endif //A1_BASE_TYPES_HPP
