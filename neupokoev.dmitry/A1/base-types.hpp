#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

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

struct triangle_t
{
  point_t pos;
  double sideA;
  double sideB;
  double sideC;
};

#endif
