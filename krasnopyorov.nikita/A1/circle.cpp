#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <math.h>


Circle::Circle(double radius, point_t dot):
  centre_(dot),
  r_(radius)
{
  if (r_ <= 0)
  {
    std::cout << "Incorrect values" << std::endl;
    exit(0);
  }
}

double Circle::getArea() const
{
  return M_PI * r_ * r_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = frameRect.height = 2 * r_;
  frameRect.pos = centre_;
  return frameRect;
}

void Circle::move(double deltax, double deltay)
{
  centre_.x += deltax;
  centre_.y += deltay;
}

void Circle::move(const point_t &dot)
{
  centre_ = dot;
}

void Circle::writeChanges() const
{
  std::cout << "New coordinates of centre (" << centre_.x << "," << centre_.y << ")" << std::endl;
}
