#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t position;
  double width;
  double height;
};

#endif //BASE_TYPES_HPP