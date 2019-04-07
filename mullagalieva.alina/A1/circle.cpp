#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t& pos, double radius) :
  centre_(pos),
  radius_(radius)
{
  assert(radius_ >= 0.0 && "Invalid circle radius");
}

Circle::Circle(double x, double y, double radius) :
  centre_({x, y}),
  radius_(radius)
{
  assert(radius_ >= 0.0 && "Invalid circle radius");
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, centre_};
}

void Circle::move(const point_t& point)
{
  centre_ = point;
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

point_t Circle::getPos() const
{
  return centre_;
}
