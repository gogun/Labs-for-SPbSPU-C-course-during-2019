#include "circle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Circle::Circle(const point_t &pos, const double &radius) : 
  Shape(pos), 
  radius_(radius)
{
  assert(radius >= 0.0);
}

Circle::Circle(const double &x, const double &y, const double &radius) :
  Circle({x, y}, radius)
{ }

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void Circle::printFeatures() const
{
  std::cout << "Circle information:\nradius: " << radius_ << "\n";
}
