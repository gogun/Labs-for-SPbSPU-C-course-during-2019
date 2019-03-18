//
// Created by Артур on 18.03.2019.
//

#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &point, const double &width, const double &height)
{
  width_ = width;
  position_ = point;
  height_ = height;
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t rectangle = {width_, height_, position_};
  return rectangle;
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
