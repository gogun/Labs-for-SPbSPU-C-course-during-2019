//
// Created by Артур on 18.03.2019.
//
#include "circle.hpp"

#include <cassert>
#include <math.h>


Circle::Circle(const point_t &point, double radius) :
  position_(point),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, position_};
}

void Circle::move(const point_t &point)
{
  position_ = point;
}

void Circle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

point_t Circle::getCenter() const
{
  return position_;
}
