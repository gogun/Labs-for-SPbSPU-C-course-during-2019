#include "circle.hpp"

#include <iostream>
#include <cmath>

gnatishin::Circle::Circle(const point_t &pos, double radius) :
  center_(pos),
  radius_(radius)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Radius cannot be less than zero");
  }
}

double gnatishin::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

gnatishin::rectangle_t gnatishin::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

gnatishin::point_t gnatishin::Circle::getPosition() const
{
  return center_;
}

void gnatishin::Circle::move(const point_t &center)
{
  center_ = center;
}

void gnatishin::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void gnatishin::Circle::scale(double scaleFactor)
{
  if (scaleFactor < 0.0)
  {
    throw std::invalid_argument("Circle scale factor cannot be less than zero.");
  }
  else
  {
    radius_ *= scaleFactor;
  }
}
