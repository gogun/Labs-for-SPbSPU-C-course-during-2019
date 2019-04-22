#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &pos, double radius) :
  pos_(pos),
  radius_(radius)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, radius_ * 2, radius_ * 2};
}

void Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}


void Circle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Circle radius is (" << radius_
            << ") Centre is (" << pos_.x << ","
            << pos_.y << ")\n"
            << "Frame rectangle width = " << rectangle.width
            << ", height = " << rectangle.height << "\n"
            << "Area = " << getArea() << "\n\n";
}
