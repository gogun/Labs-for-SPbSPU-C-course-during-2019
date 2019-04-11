#include "circle.hpp"

#include <cmath>
#include <stdexcept>

const double M_PI = 3.14;
korolev::Circle::Circle(const point_t &center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive");
  }
}

korolev::Circle::Circle(double x, double y, double radius):
  center_({x, y}),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive");
  }
}

double korolev::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

korolev::rectangle_t korolev::Circle::getFrameRect() const
{
  return rectangle_t{ center_, radius_, radius_ };
}

double korolev::Circle::getRadius() const
{
  return radius_;
}

void korolev::Circle::move(const point_t &position)
{
  center_ = position;
}

void korolev::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void korolev::Circle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient must be positive");
  }
  radius_ *= coefficient;
}

