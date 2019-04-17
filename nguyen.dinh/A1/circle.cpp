#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const double radius, const point_t &center) :
  radius_(radius),
  pos_(center)
{
  assert(radius  > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2.0 * radius_, 2.0 * radius_, pos_};
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

void Circle::printInfo() const
{
  std::cout << "Circle:"
  << "\n  Radius: " << radius_
  << "\n  Position:"
  << "\n    x: " << pos_.x
  << "\n    y: " << pos_.y
  << "\n  Area: " << this->getArea() << "\n\n";
}
