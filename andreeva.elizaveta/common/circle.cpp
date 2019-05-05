#include "circle.hpp"
#include <cmath>
#include <stdexcept>

andreeva::Circle::Circle(const point_t &point, double rad):
  center_(point),
  radius_(rad)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius cannot be negative");
  }
}

double andreeva::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

andreeva::rectangle_t andreeva::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void andreeva::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void andreeva::Circle::move(const point_t &point)
{
  center_ = point;
}

void andreeva::Circle::scale(double factor)
{
  if (factor > 0.0)
  {
    radius_ *= factor;
  }
  else
  {
    throw std::invalid_argument("Factor cannot be negative");
  }
}
