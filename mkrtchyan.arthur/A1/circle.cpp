#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2*radius_, 2*radius_, pos_};
}

void Circle::move(point_t point)
{
  pos_ = point;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
