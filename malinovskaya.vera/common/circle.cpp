#include "circle.hpp"
#include <iostream>
#include <cmath>

malinovskaya::Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius should be positive");
  }
}

double malinovskaya::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

malinovskaya::rectangle_t malinovskaya::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void malinovskaya::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void malinovskaya::Circle::move(const point_t &point)
{
  center_ = point;
}

void malinovskaya::Circle::print() const
{
  std::cout << "Center: (" << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << std::endl;
}

void malinovskaya::Circle::scale(const double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("Scale coefficient should be positive");
  }
  else
  {
    radius_ *= coeff;
  }
}
