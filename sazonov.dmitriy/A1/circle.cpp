#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  assert(radius_ >= 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, center_ };
}

void Circle::move(const point_t &newPos)
{
  center_ = newPos;
}

void Circle::move(double ax, double ay)
{
  center_.x += ax;
  center_.y += ay;
}

point_t Circle::getPos() const
{
  return center_;
}
