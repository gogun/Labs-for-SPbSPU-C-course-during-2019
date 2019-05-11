#define _USE_MATH_DEFINES

#include "circle.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

barekov::Circle::Circle(const point_t& pos, double radius) :
  centre_(pos),
  radius_(radius)
{
  if (radius_ < 0.0) //if radius is equal to 0, it is technically a degenerate circle.
  {
    throw std::invalid_argument("Radius must be a non-negative number");
  }
}

barekov::Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{ }

double barekov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

barekov::rectangle_t barekov::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, centre_};
}

barekov::point_t barekov::Circle::getPos() const
{
  return centre_;
}

void barekov::Circle::showScalableParameters() const
{
  std::cout << "\nThe radius of the circle is " << radius_ << "\n";
}

void barekov::Circle::move(const point_t& centre)
{
  centre_ = centre;
}

void barekov::Circle::move(double deltaX, double deltaY)
{
  centre_.x += deltaX;
  centre_.y += deltaY;
}

void barekov::Circle::scale(double scaleFactor)
{
  if (scaleFactor < 0.0)
  {
    throw std::invalid_argument("Circle scale factor must be a non-negative number");
  }
  else
  {
    radius_ *= scaleFactor;
  }
}
