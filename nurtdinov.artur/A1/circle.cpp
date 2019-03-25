//
// Created by Артур on 18.03.2019.
//

#include <iostream>
#include "circle.hpp"

Circle::Circle(const point_t &point, const double &radius):
  position_(point),
  radius_(radius)
{
  if (radius <= 0)
  {
    std::cerr<<"Invalid value of radius";
  }
}

double Circle::getArea() const
{
  return radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, position_};
}

void Circle::move(const point_t &point)
{
  position_ = point;
}

void Circle::move(const double &dx, const double &dy)
{
  position_.x += dx;
  position_.y += dy;
}

point_t Circle::getPosition() const
{
  return position_;
}
