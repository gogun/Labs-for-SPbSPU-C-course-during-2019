#include "circle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
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
  std::cout << "Radius: " << radius_;
  std::cout << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &newPos)
{
  pos_ = newPos;
}