#include "circle.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

Circle::Circle(const point_t & center, double radius):
  center_(center),
  radius_(radius),
{
  assert(radius_ >= 0.0);
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, center_ };
}

double Circle::getArea() const
{
	return M_PI * radius_ * radius_;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t & point)
{
  center_ = point;
}

