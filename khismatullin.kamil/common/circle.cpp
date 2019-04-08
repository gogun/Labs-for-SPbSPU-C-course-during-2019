#include "circle.hpp"
#include <iostream>
#include <math.h>


khismatullin::Circle::Circle(const point_t &pos, const double radius) :
    center_(pos),
    radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius should be > 0");
  }
}

double khismatullin::Circle::getArea() const
{
  return pow(radius_, 2) * M_PI;
}

khismatullin::rectangle_t khismatullin::Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void khismatullin::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void khismatullin::Circle::move(const point_t &point)
{
  center_ = point;
}

khismatullin::point_t khismatullin::Circle::getCenter() const
{
  return center_;
}

double khismatullin::Circle::getRadius() const
{
  return radius_;
}

void khismatullin::Circle::show() const
{
  std::cout << "[Circle]:\n";
  std::cout << "Center : (" << getCenter().x << ", " << getCenter().y << ")\n";
  std::cout << "Radius : " << getRadius() << "\n";
  std::cout << "Height of frame rectangle : " << getFrameRect().height << "\n";
  std::cout << "Width of frame rectangle  : " << getFrameRect().width << "\n";
  std::cout << "Area   : " << getArea() << "\n";
}

void khismatullin::Circle::scale(const double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Multiplier of scale should be > 0");
  }
  radius_ *= multiplier;
}
