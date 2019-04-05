#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

Circle::Circle(const point_t & centre, double radius):
  Shape(centre),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frameRect = { 2 * radius_,
    2 * radius_ ,
    centre_, };
  return frameRect;
}

void Circle::move(const point_t & newCentre)
{
  centre_ = newCentre;
}

void Circle::move(double dX, double dY)
{
  centre_.x += dX;
  centre_.y += dY;
}

void Circle::setRadius(double newRadius)
{
  radius_ = newRadius;
}
