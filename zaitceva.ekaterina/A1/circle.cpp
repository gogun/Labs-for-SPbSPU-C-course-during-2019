#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &centre, double radius):
  pos_(centre),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2*radius_, 2*radius_, pos_};
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
