#include "circle.hpp"
#include <cmath>
#include <cassert>
#include <iostream>

Circle::Circle(double radius, point_t pos):
  radius_(radius)
  pos_(pos)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

Circle_t Circle::getFrameRect() const
{
  rectangle_t frameCirc;
  frameCirc.height = frameCirc.width = radius_ * 2;
  frameCirc.pos = pos_;
  return frameCirc;
}

void Circle::displayData() const
{
  std::cout << "Radius: " << radius_
    << "\nPosition: (" << options_.pos.x << ';' << options_.pos.y << ')';
}

void Circle::move (double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move (point_t newPos)
{
  pos_ = newPos;
}
