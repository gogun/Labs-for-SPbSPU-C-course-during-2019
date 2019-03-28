#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle(double height, double width, const point_t &center) :
  height_(height),
  width_(width),
  center_(center)
{
  if (height_ <= 0.0)
  {
    std::cerr << "Invalid rectangle height" << std::endl;
  }
  if (width_ <= 0.0)
  {
    std::cerr << "Invalid rectangle width" << std::endl;
  }
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { height_, width_, center_ };
}

void Rectangle::move(const point_t &newPos)
{
  center_ = newPos;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

point_t Rectangle::getPos() const
{
  return center_;
}