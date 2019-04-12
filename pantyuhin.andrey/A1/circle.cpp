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

point_t Circle::getPos() const
{
  return centre_;
}

double Circle::getRadius() const
{
  return radius_;
}

void Circle::printParameters() const
{
  point_t point = getPos();
  std::cout << "circle: x=" << point.x << ", y=" << point.y << ", rad="
      << getRadius() << std::endl << std::endl;
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
