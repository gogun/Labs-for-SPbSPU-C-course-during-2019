#include "circle.hpp"
#include <cmath>
#include <cassert>
#include <iostream>

Circle::Circle(double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frameCirc;
  frameCirc.height = frameCirc.width = radius_ * 2;
  frameCirc.pos = pos_;
  return frameCirc;
}

void Circle::displayData() const
{
  std::cout << "Radius: " << radius_
    << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

void Circle::move (double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move (const point_t &newPos)
{
  pos_ = newPos;
}
