#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <math.h>

Circle::Circle(const point_t &center, double radius):
  radius_(radius),
  center_(center)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}


rectangle_t Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void Circle::writeInfo() const
{
  rectangle_t rectangleExp = getFrameRect();
  std::cout << "Information about the Circle: \n";
  std::cout << "Radius: " << radius_ << "\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ") \n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle: width = " << rectangleExp.width << ", height = " << rectangleExp.height << "\n"
            << std::endl;
}
