#include "circle.hpp"
#include <cassert>
#include <cmath>
#include "base-types.hpp"


Circle::Circle(const point_t & position,const double &radius) :
  center_(position),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const double &shift_x,const double &shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void Circle::move(const point_t & position)
{
  center_ = position;
}
