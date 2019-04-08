#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &center, const double &radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ >= 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t &position)
{
  center_ = position;
}

void Circle::move(const double &move_x, const double &move_y)
{
  center_.x += move_x;
  center_.y += move_y;
}