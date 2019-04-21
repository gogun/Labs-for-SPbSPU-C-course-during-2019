#include "circle.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

dyu::Circle::Circle(double radius, const point_t &pos) :
  radius_(radius),
  pos_(pos)
{
  if (radius < 0.0)
  {
    throw std::invalid_argument("radius is wrong");
  }
}

double dyu::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

  dyu::rectangle_t dyu::Circle::getFrameRect() const
{
  return rectangle_t {2 * radius_, 2 * radius_, pos_};
}

void dyu::Circle::move(const point_t &pos)
{
  pos_.x = pos.x;
  pos_.y = pos.y;
}

void dyu::Circle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}

void dyu::Circle::scale(double coeficient)
{
  if (coeficient < 0)
  {
    throw std::invalid_argument("coeficient is wrong");
  }
  radius_ *= coeficient;
}
