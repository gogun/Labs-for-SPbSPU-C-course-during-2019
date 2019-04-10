#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

skudar::Circle::Circle(const point_t &position, double radius) :
  center_(position),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

skudar::Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{
  assert(radius_ > 0.0);
}

double skudar::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

skudar::rectangle_t skudar::Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void skudar::Circle::move(point_t point)
{
  center_ = point;
}

void skudar::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void skudar::Circle::scale(double factor)
{
  assert(factor > 0.0);
  radius_ *= factor;
}
