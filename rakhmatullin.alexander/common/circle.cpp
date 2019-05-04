#include "circle.hpp"
#include <cmath>
#include <stdexcept>


rakhmatullin::Circle::Circle(const rakhmatullin::point_t &position, double radius) :
  center_(position),
  radius_(radius)
{
  if (radius < 0.0) {
    throw std::invalid_argument("Incorrect circle radius. Radius should be positive");
  }
}

double rakhmatullin::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rakhmatullin::rectangle_t rakhmatullin::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void rakhmatullin::Circle::move(double shift_x, double shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void rakhmatullin::Circle::move(const rakhmatullin::point_t &position)
{
  center_ = position;
}

void rakhmatullin::Circle::scale(double factor)
{
  if (factor < 0.0) {
    throw std::invalid_argument("Factor of scale should be positive");
  }
  radius_ *= factor;
}
