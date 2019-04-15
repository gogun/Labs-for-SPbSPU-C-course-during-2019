#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  pos_(center)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2.0 * radius_, 2.0 * radius_, pos_};
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

void Circle::printInfo() const
{
  std::cout << "Circle:"
      << std::endl << "  Radius: " << radius_
      << std::endl << "  Position: "
      << std::endl << "    x: " << pos_.x
      << std::endl << "    y: " << pos_.y
      << std::endl << "  Area: " << this->getArea()
      << std::endl << std::endl;
}
