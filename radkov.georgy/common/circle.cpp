#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace radkov;

Circle::Circle(const point_t &pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("invalid_radius");
  }
}

double Circle::getRadius() const noexcept
{
  return radius_;
}

double Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const noexcept
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void Circle::move(double dx, double dy) noexcept
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &pos) noexcept
{
  pos_ = pos;
}

void Circle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid_scale");
  }
  
  radius_ *= k;
}
