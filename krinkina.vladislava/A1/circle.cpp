#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>
#include <cassert>
#include <iostream>

Circle::Circle(const point_t &centre, double radius) :
  centre_(centre),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t
  {
    2 * radius_,
    2 * radius_,
    centre_
  };
}

void Circle::move(const point_t &centre)
{
  centre_ = centre;
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void Circle::printInfo() const
{
  std::cout << "The coordinates of the centre (" << centre_.x << "," << centre_.y << ")\n";
  std::cout << "radius = " << radius_ << '\n';
  std::cout << "area = " << Circle::getArea() << '\n';
  rectangle_t rectagle = getFrameRect();
  std::cout << "parameters FrameRect:\n";
  std::cout << "height = " << rectagle.height << ", width =" << rectagle.width << '\n';
  std::cout << "coordinates of the centre: (" << rectagle.pos.x << "," << rectagle.pos.y << ")\n";
}
