#ifndef POINT_T_HPP
#define POINT_T_HPP

struct point_t
{
  double x;
  double y;
};

#endif // !POINT_T_HPP

#ifndef RECTANGLE_T_HPP
#define RECTANGLE_T_HPP

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};

#endif // !RECTANGLE_T_HPP