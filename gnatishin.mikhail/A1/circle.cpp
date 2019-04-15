#include "circle.hpp"

#include <cassert>
#include <cmath>

Circle::Circle(const point_t &pos, double radius) :
  center_(pos),
  radius_(radius)
{
 assert(radius_ >= 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

point_t Circle::getPosition() const
{
  return center_;
}

void Circle::move(const point_t &center)
{
  center_ = center;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
