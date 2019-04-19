#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cassert>

moreva::Circle::Circle(const point_t & center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius must be positive.");
  }
}

moreva::Circle::Circle(double centerX, double centerY, double radius) :
  Circle({centerX, centerY}, radius)
{}

double moreva::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

moreva::rectangle_t moreva::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void moreva::Circle::move(const point_t & pos)
{
  center_ = pos;
}

void moreva::Circle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void moreva::Circle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scaling factor must be positive.");
  }
  else
  {
    radius_ *= factor;
  }
}

moreva::point_t moreva::Circle::getCenter() const
{
  return center_;
}

double moreva::Circle::getRadius() const
{
  return radius_;
}

void moreva::Circle::printInfo() const
{
  std::cout << "Circle. It's center is at:" << "(" <<center_.x << ";" << center_.y << ")"
            << std::endl << "Radius is: " << radius_
            << std::endl << "Area is: " << getArea()
            << std::endl << std::endl;
}
