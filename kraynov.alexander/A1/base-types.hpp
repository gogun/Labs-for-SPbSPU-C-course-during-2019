#ifndef A1_BASE_TYPES_HPP
#define A1_BASE_TYPES_HPP
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
#endif //A1_BASE_TYPES_HPP
