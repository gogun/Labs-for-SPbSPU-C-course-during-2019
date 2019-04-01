#define _USE_MATH_DEFINES

#include <math.h>
#include <stdexcept>
#include "../include/circle.hpp"

Circle::Circle(double radius, const point_t pos)
{
  if (radius <= 0)
    throw std::out_of_range("Radius is out of range");

  this->radius = radius;
  this->centre = pos;
}

double Circle::getArea()
{
  return M_PI * pow(this->radius, 2);
}

rectangle_t Circle::getFrameRect()
{
  double diametr = 2 * this->radius;
  return rectangle_t(diametr, diametr, this->centre);
}
