#include "circle.hpp"

#include <cmath>
#include <stdexcept>

seleznev::Circle::Circle(double r, point_t p):
  Shape(p),
  radius_(r)
{
  if (radius_ <= 0)
    throw std::out_of_range("Radius is out of range");
}

double seleznev::Circle::getArea() const
{
  return M_PI * pow(radius_, 2);
}

seleznev::rectangle_t seleznev::Circle::getFrameRect() const
{
  double diametr = 2 * radius_;

  return {diametr, diametr, centre_};
}

void seleznev::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::out_of_range("Coefficient is out of range");
  }
  radius_ *= coefficient;
}

double seleznev::Circle::getRadius()
{
  return radius_;
}
