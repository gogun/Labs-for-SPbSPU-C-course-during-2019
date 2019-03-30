//
// Created by Артур on 18.03.2019.
//

#include "rectangle.hpp"

#include <iostream>

Rectangle::Rectangle(const point_t &point, double width, double height)
{
  if (width <= 0)
  {
    std::cerr << "Invalid value of width";
  }
  if (height <= 0)
  {
    std::cerr << "Invalid value of height";
  }
  position_ = point;
  width_ = width;
  height_ = height;
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, position_};
}

void Rectangle::move(const point_t &point)
{
  position_ = point;
}

void Rectangle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

point_t Rectangle::getCenter() const
{
  return position_;
}
