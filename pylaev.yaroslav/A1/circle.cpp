#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Circle::Circle(const point_t &center,
    double radius):
  Shape(center),
  radius_(radius)
  {
    assert((radius_ != 0) && ("It is a point"));
    assert((radius_ > 0) && ("Invalid value of radius"));
  }

double Circle::getRadius() const
{
  return radius_;
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void Circle::printSpec() const
{
  std::cout << "    Area of our circle with radius = " << getRadius() << " is " << getArea() << " square units\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "    Center of the frame rectangle with width = " << frameRectangle.width
      << " and height = " << frameRectangle.height << std::endl;
  std::cout << "    is located in point (" << frameRectangle.pos.x << "; "
      << frameRectangle.pos.y << ")\n";
}
