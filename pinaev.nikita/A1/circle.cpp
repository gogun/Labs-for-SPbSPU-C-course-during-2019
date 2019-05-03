#include "circle.hpp"
#include "base-types.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &centr, const double radius):
  radius_(radius),
  centr_(centr)
{
  assert(radius >= 0);
}
double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}
rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, centr_ };
}
void Circle::move(const double dx, const double dy)
{
  centr_.x += dx;
  centr_.y += dy;
}
void Circle::move(const point_t &newPoint)
{
  centr_ = newPoint;
}
void Circle::showResults() const
{
  std::cout << "Radius is " << radius_ << std::endl
    << "Center at: (" << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << std::endl;
}
