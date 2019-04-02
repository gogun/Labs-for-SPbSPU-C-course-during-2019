#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <math.h>

Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  double radius = 2 * radius_;
  return {center_, radius, radius};
}

void Circle::printParams() const
{
  std::cout << "-Coordination of the center (" << center_.x << "," << center_.y << ")\n";
  std::cout << "-Radius = " << radius_ << '\n';
  std::cout << "-Area = " << Circle::getArea() << '\n';
  rectangle_t frameRect = getFrameRect();
  std::cout << "-Parameters of FrameRect\n";
  std::cout << "--Coordination of the center (" << frameRect.pos.x << "," << frameRect.pos.y << ")\n";
  std::cout << "--Width = " << frameRect.width << ", Height = " << frameRect.height << '\n';
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &point)
{
  center_ = point;
}
