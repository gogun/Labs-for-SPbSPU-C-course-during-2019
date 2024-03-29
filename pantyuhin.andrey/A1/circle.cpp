#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(point_t centre, double radius):
  centre_(centre),
  radius_(radius)
{
  assert((radius_ > 0) && "radius of circle can't be <=0 ");
}

Circle::Circle(double x, double y, double radius):
  Circle({x, y}, radius)
{ }

void Circle::printParameters() const
{
  std::cout << "circle: x=" << centre_.x << ", y=" << centre_.y << ", rad="
      << radius_ << std::endl << std::endl;
}

double Circle::getArea() const
{
  return (M_PI * pow(radius_, 2));
}

rectangle_t Circle::getFrameRect() const
{
  return {centre_, radius_ * 2, radius_ * 2};
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void Circle::move(point_t centre)
{
  centre_ = centre;
}
