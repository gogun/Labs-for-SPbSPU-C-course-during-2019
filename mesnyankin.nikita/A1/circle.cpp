#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>
#include <iostream>
#include "circle.hpp"

Circle::Circle(const double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0);
}

Circle::Circle(const double radius, const double posx, const double posy) :
  radius_(radius),
  pos_({ posx, posy })
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}


double Circle::getRadius()
{
  return radius_;
}

point_t Circle::getPos()
{
  return pos_;
}

rectangle_t Circle::getFrameRect() const
{
  return { pos_, radius_*2, radius_ * 2 };
}
