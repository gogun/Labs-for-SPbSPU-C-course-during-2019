#include "circle.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(double radius, const point_t & center):
  radius_(radius),
  center_(center)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t & point)
{
  center_ = point;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::show() const
{
  std::cout << "Circle's area: " << getArea() << std::endl;
  std::cout << "Rectangle's width: " << getFrameRect().width << std::endl;
  std::cout << "Rectangle's height: " << getFrameRect().height << std::endl;
  std::cout << "Rectangle's center: (" << getFrameRect().pos.x
            << "; " << getFrameRect().pos.y << ")" << std::endl;
}
