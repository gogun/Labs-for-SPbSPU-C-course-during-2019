#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <iostream>

struct point_t
{
  double x;
  double y;
};

std::ostream & operator <<(std::ostream& os, const point_t& r);

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};

std::ostream & operator <<(std::ostream& os, const rectangle_t& r);
#endif
