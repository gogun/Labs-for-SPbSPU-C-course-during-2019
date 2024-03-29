#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &goal, double rad):
  center_(goal),
  radius_(rad)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void Circle::move(const point_t &goal)
{
  center_ = goal;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::show() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << std::endl
      << "Coordinates of centre circle (" << center_.x
      << ";" << center_.y << ")" << std::endl
      << "radius = " << radius_ << std::endl
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << std::endl
      << "Area = " << getArea() << std::endl << std::endl;
}
