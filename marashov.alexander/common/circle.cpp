#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

marashov::Circle::Circle(const point_t & center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius of the circle must be positive");
  }
}

marashov::Circle::Circle(double centerX, double centerY, double radius):
  Circle({centerX, centerY}, radius)
{ }

double marashov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

marashov::rectangle_t marashov::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void marashov::Circle::move(const point_t & pos)
{
  center_ = pos;
}

void marashov::Circle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void marashov::Circle::scale(double scaleAmount)
{
  if (scaleAmount <= 0)
  {
    throw std::invalid_argument("Scale amount must be positive");
  }
  radius_ *= scaleAmount;
}

void marashov::Circle:: writeInfo() const
{
  std::cout << "Circle. Center at (" << center_.x << "; " << center_.y << ")"
      << std::endl << "Radius = " << radius_
      << std::endl << "Area = " << getArea()
      << std::endl << std::endl;
}

marashov::point_t marashov::Circle::getCenter() const
{
  return center_;
}

double marashov::Circle::getRadius() const
{
  return radius_;
}
