#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const point_t & center, double radius):
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0);
}

Circle::Circle (double centerX, double centerY, double radius):
  Circle({centerX,centerY},radius)
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

void Circle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}

void Circle:: printInfo() const
{
  std::cout << "Circle. It's center is at:" << "("<<center_.x << ";" << center_.y << ")"
            << std::endl << "Radius is : " << radius_
            << std::endl << "Area is : " << getArea()
            << std::endl << std::endl;

}
