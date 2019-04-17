#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <math.h>

uzhegov::Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  if(radius <= 0)
  {
    throw std::invalid_argument("Radius should be positive");
  }
}

double uzhegov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

uzhegov::rectangle_t uzhegov::Circle::getFrameRect() const
{
  double radius = 2 * radius_;
  return {center_, radius, radius};
}

void uzhegov::Circle::printParams() const
{
  std::cout << "-Coordination of the center (" << center_.x << "," << center_.y << ")\n";
  std::cout << "-Radius = " << radius_ << '\n';
  std::cout << "-Area = " << Circle::getArea() << '\n';
  rectangle_t frameRect = getFrameRect();
  std::cout << "-Parameters of FrameRect\n";
  std::cout << "--Coordination of the center (" << frameRect.pos.x << "," << frameRect.pos.y << ")\n";
  std::cout << "--Width = " << frameRect.width << ", Height = " << frameRect.height << '\n';
}

void uzhegov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void uzhegov::Circle::move(const point_t &point)
{
  center_ = point;
}

void uzhegov::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient should be positive");
  }
  radius_ *= coefficient;
}
