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
  std::cout << "Area is " << getArea() << " square units\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "Frame rectangle width = " << frameRectangle.width << std::endl;
  std::cout << "Frame rectangle height = " << frameRectangle.height << std::endl;
  std::cout << "Frame rectangle center X: " << frameRectangle.pos.x << "; "
  std::cout << "Frame rectangle center Y: " << frameRectangle.pos.y << std::endl;
}
