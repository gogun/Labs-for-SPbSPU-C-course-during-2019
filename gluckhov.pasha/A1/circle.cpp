#include "circle.hpp"
#include <cmath>

Circle::Circle(double radius, point_t pos):
  radius_(radius)
  pos_(height)
{}

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

void Circle::move (double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move (point_t newPos)
{
  pos_ = newPos;
}
