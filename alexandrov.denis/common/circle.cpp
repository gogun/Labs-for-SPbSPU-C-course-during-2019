#include "circle.hpp"

#include <stdexcept>
#include <cmath>

using namespace alexandrov;

alexandrov::Circle::Circle(const point_t & center, const double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("The radius of the circle must be greater than zero.");
  }
}

void alexandrov::Circle::move(const point_t & newPoint)
{
  center_ = newPoint;
}

void alexandrov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void alexandrov::Circle::scale(const double factor)
{
  if (factor > 0.0)
  {
    radius_ *= factor;
  }
  else
  {
    throw std::invalid_argument("Method scale must have a factor greater than zero.");
  }
}

double alexandrov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t alexandrov::Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}
