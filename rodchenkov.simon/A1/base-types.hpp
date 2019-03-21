#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t final
{
  double x;
  double y;
};

struct rectangle_t final
{
  double  height;
  double  width;
  point_t pos;
};

#endif // BASE_TYPES_HPP
