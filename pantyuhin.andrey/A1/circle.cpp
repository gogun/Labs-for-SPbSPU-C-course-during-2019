#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(point_t centre, double radius):

  centre_(centre),
  radius_(radius)
{
  assert(radius_ > 0 && "radius of circle can't be <=0");
}

Circle::Circle(double x, double y, double radius):
  radius_(radius)
{
  assert(radius_ > 0 && "radius of circle can't be <=0");
  centre_.x = x;
  centre_.y = y;
  }

point_t Circle::getPos() const
{
  return centre_;
}

double Circle::getRadius() const
{
  return radius_;
}

double Circle::getArea() const
{
  return (M_PI*pow(radius_, 2));
}

rectangle_t Circle::getFrameRect() const
{
  return {centre_, radius_*2, radius_*2};
}

void Circle::move(double dx, double dy)
{
  centre_.x = centre_.x + dx;
  centre_.y = centre_.y + dy;
}

void Circle::move(point_t centre)
{
  centre_ = centre;
}
