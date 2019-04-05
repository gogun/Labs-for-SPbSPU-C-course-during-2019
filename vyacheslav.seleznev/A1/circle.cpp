#include "circle.hpp"

#include <cmath>
#include <cassert>

Circle::Circle(double radius, const point_t pos)
{
  assert(radius > 0);

  this->radius = radius;
  this->centre = pos;
}

double Circle::getArea() const
{
  return M_PI * pow(this->radius, 2);
}

rectangle_t Circle::getFrameRect() const
{
  double diametr = 2 * this->radius;
  return {diametr, diametr, this->centre};
}
