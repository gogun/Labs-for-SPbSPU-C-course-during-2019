#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <math.h>
#include <stdexcept>

lutsenko::Circle::Circle(double radius, const point_t & pos):
  radius_(radius),
  pos_(pos)
{
  if (radius <= 0)
	{
		throw std::invalid_argument("radius should be greater than	zero");
	};
}

double lutsenko::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

lutsenko::rectangle_t lutsenko::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void lutsenko::Circle::move(const point_t & point)
{
  pos_ = point;
}

void lutsenko::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void lutsenko::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
	{
		throw std::invalid_argument("coefficient should be greater than	zero");
	};
  radius_ *= coefficient;
}
