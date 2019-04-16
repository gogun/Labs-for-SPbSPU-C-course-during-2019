#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double x;
  double y;

  point_t & operator +(const point_t & point)
  {
    return {x + point.x, y + point.y};
  }

  point_t & operator -(const point_t & point)
  {
    return {x - point.x, y - point.y};
  }
};

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};
#endif
