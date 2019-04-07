//
// Created by Артур on 18.03.2019.
//
#include "circle.hpp"

#include <cassert>
#include <math.h>


nurtdinov::Circle::Circle(const nurtdinov::point_t &point, double radius) :
  position_(point),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double nurtdinov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

nurtdinov::rectangle_t nurtdinov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, position_};
}

void nurtdinov::Circle::move(const nurtdinov::point_t &point)
{
  position_ = point;
}

void nurtdinov::Circle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

nurtdinov::point_t nurtdinov::Circle::getCenter() const
{
  return position_;
}

void nurtdinov::Circle::scale(double rate)
{
  assert(rate > 0.0);
  radius_ *= rate;
}

