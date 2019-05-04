#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <math.h>


Circle::Circle(const point_t &pos, const double radius) :
    center_(pos),
    radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return pow(radius_, 2) * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

point_t Circle::getCenter() const
{
  return center_;
}

double Circle::getRadius() const
{
  return radius_;
}

void Circle::show() const
{
  std::cout << "[Circle]:\n";
  std::cout << "Center : (" << getCenter().x << ", " << getCenter().y << ")\n";
  std::cout << "Radius : " << getRadius() << "\n";
  std::cout << "Height of frame rectangle : " << getFrameRect().height << "\n";
  std::cout << "Width of frame rectangle  : " << getFrameRect().width << "\n";
  std::cout << "Area   : " << getArea() << "\n";
}
