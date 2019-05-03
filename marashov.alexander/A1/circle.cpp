#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

Circle::Circle(const point_t & center, double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius > 0);
}

Circle::Circle(double centerX, double centerY, double radius) :
  Circle({centerX, centerY}, radius)
{ }

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void Circle::move(const point_t & pos)
{
  center_ = pos;
}

void Circle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void Circle:: writeInfo() const
{
  std::cout << "Circle. Center at (" << center_.x << "; " << center_.y << ")"
            << std::endl << "Radius = " << radius_
            << std::endl << "Area = " << getArea()
            << std::endl << std::endl;
}
