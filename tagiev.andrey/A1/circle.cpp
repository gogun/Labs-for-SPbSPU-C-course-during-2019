#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius>=0);
}
rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}
void Circle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}
void Circle::move(point_t newPoint)
{
  center_ = newPoint;
}
