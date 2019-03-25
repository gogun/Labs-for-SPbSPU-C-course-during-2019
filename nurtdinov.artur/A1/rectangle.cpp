//
// Created by Артур on 18.03.2019.
//

#include <iostream>
#include <assert.h>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &point, const double &width, const double &height)
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

void Rectangle::move(const double &dx, const double &dy)
{
  position_.x += dx;
  position_.y += dy;
}

point_t Rectangle::getPosition() const
{
  return position_;
}
