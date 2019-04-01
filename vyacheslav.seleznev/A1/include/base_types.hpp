#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

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

  rectangle_t(double w, double h, point_t p)
  {
    width = w;
    height = h;
    pos = p;
  }
};

#endif
