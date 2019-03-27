#define _USE_MATH_DEFINES
#include "circle.hpp"

#include <cassert>
#include <cmath>

Circle::Circle(const point_t& pos, double radius) :
  centre_(pos),
  radius_(radius)
{
  assert (radius_ >= 0.0); //if radius is equal to 0, it is technically a degenerate circle.
}

Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, centre_};
}

point_t Circle::getPos() const
{
  return centre_;
}

void Circle::move(const point_t& centre)
{
  centre_ = centre;
}

void Circle::move(double mx, double my)
{
  centre_.x += mx;
  centre_.y += my;
}
