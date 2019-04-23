#include "circle.hpp"
#include <stdexcept>
#include <cmath>

kozhin::Circle::Circle(const kozhin::point_t& center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Circle radius must be positive.");
  }
}

double kozhin::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

kozhin::rectangle_t kozhin::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

kozhin::point_t kozhin::Circle::getCenter() const
{
  return center_;
}

void kozhin::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void kozhin::Circle::move(const kozhin::point_t& point)
{
  center_ = point;
}

void kozhin::Circle::scale(double rate)
{
  if (rate <= 0.0)
  {
    throw std::invalid_argument("Scale rate must be positive.");
  }
  radius_ *= rate;
}
