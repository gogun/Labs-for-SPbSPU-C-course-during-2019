#include "triangle.hpp"
#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t& pos, double base, double height):
  pos_{pos},
  base_{base},
  height_{height}
{
  assert((base > 0) && (height > 0));
}
  
double Triangle::getArea() const
{
  return (base_ * height_) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  return {pos_, base_, height_};
}

void Triangle::move(const point_t& pos)
{
  pos_ = pos;
}

void Triangle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
