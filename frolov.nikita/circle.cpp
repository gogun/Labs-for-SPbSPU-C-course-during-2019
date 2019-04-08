#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(double radius, const point_t &center) :
  center_(center),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &center)
{
  center_.x = center.x;
  center_.y = center.y;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, {center_.x, center_.y}};
}

void Circle::showPoint() const
{
  std::cout << "the point on the x-axis " << center_.x << "\n";
  std::cout << "the point on the y-axis " << center_.y << "\n";
}
