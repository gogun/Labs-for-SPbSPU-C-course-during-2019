#include "circle.hpp"

#include <cmath>
#include <cassert>

Circle::Circle(double r, point_t p):
  radius_(r),
  Shape(p)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return M_PI * pow(radius_, 2);
}

rectangle_t Circle::getFrameRect() const
{
  double diametr = 2 * radius_;

  return {diametr, diametr, centre_};
}
