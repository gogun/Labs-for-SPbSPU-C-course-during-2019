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
  rectangle_t frameRect;
  frameRect.width = 2 * radius_;
  frameRect.height = 2 * radius_;
  frameRect.pos = pos_;
  return frameRect;
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

void Circle::move(const double dx, const double dy)
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
