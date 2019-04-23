#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

frolov::Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Invalid radius!");
  }
}

double frolov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void frolov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void frolov::Circle::move(const point_t &center)
{
  center_ = center;
}

frolov::rectangle_t frolov::Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void frolov::Circle::showPoint() const
{
  std::cout << "the point on the x-axis " << center_.x << "\n";
  std::cout << "the point on the y-axis " << center_.y << "\n";
}

void frolov::Circle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Area can't be negative");
  }
  radius_ *= factor;
}
