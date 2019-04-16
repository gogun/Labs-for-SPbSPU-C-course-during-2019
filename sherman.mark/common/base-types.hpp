#ifndef COMMON_BASE_TYPES_HPP
#define COMMON_BASE_TYPES_HPP

namespace sherman
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
