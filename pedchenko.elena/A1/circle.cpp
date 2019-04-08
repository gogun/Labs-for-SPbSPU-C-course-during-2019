#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <math.h>

Circle::Circle(const point_t & center, double radius):
  center_(center),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}



rectangle_t Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void Circle::move(const point_t & centerPoint)
{
  center_ = centerPoint;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::writeInfo() const
{
  std::cout << "Circle: \n";
  std::cout << "1) Center: (" << center_.x << "," << center_.y << ") \n";
  std::cout << "2) Radius: " << radius_ << "\n";
  std::cout << "3) Area: " << getArea() << "\n";
  rectangle_t rectFrame = getFrameRect();
  std::cout << "Frame Rectangle: width = " << rectFrame.width << ", height = " << rectFrame.height << "\n"
            << std::endl;
}
