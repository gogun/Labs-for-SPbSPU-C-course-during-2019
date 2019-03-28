#ifndef BASE_TYPES_HPP_
#define BASE_TYPES_HPP_

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t center;
  double width;
  double height;
};

#endif
