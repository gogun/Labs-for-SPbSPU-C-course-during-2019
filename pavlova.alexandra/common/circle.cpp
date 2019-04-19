#include <cassert>
#include <cmath>
#include <stdexcept>
#include "circle.hpp"

pavlova::Circle::Circle(double radius, const point_t &center):
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius is negative or zero");
  }
}

double pavlova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

pavlova::rectangle_t pavlova::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void  pavlova::Circle::move(const point_t &point)
{
  center_ = point;
}

void pavlova::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void pavlova::Circle::scale(double coeff)
{
  if (coeff <= 0)
  {
    throw std::invalid_argument("Coeff is negative or zero");
  }
  else
  {
    radius_ *= coeff;
  }
}
