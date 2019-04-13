#include "triangle.hpp"
#include <cassert>
#include <iostream>

Triangle::Triangle(double base, double height, const point_t &position):
  height_(height),
  base_(base),
  pos_(position)
{
  assert(base > 0.0);
  assert(height > 0.0);
}

double Triangle::getArea() const
{
  return (0.5 * base_ * height_);
}

rectangle_t Triangle::getFrameRect() const
{
  return {base_, height_, pos_};
}

void Triangle::printData() const
{
  std::cout << "Base: " << base_ << "\tHeight: " << height_;
  std::cout << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

void Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Triangle::move(const point_t &newPos)
{
  pos_ = newPos;
}
