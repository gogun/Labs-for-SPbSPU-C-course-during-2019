#include "circle.hpp"

#include <stdexcept>
#include <cmath>


nurtdinov::Circle::Circle(const nurtdinov::point_t &point, double radius) :
  position_(point),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius must be positive");
  }
}

double nurtdinov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
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

void nurtdinov::Circle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Scale ratio must be positive");
  }
  radius_ *= ratio;
}
