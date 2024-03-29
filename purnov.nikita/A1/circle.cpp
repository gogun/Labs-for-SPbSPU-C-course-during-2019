#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(double radius, const point_t & pos) :
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t { 2 * radius_ , 2 * radius_ , pos_};
}

void Circle::move(const point_t & pos)
{
  pos_.x = pos.x;
  pos_.y = pos.y;
}

void Circle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
