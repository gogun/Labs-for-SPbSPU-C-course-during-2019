#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const double radius, const point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Circle::move(const point_t point)
{
  pos_ = point;
}


double Circle::getRadius()
{
  return radius_;
}

point_t Circle::getPos()
{
  return pos_;
}

void Circle::showData()
{
  std::cout << "Circle data:" << std::endl;
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Centre position(x, y): " << pos_.x << "," << pos_.y << std::endl;
  std::cout << "FrameRect centre in: " << getFrameRect().pos.x << "," << getFrameRect().pos.y << std::endl;
  std::cout << "FrameRect width and height (are equal): " 
      << getRadius() * 2 << " | " << getRadius() * 2 << std::endl;
}

rectangle_t Circle::getFrameRect() const
{
  return { pos_, radius_*2, radius_ * 2 };
}
