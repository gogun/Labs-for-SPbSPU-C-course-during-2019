#include "rectangle.hpp"
#include <iostream>

chugaynov::Rectangle::Rectangle(const point_t &point, double width, double height):
  pos_(point),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("\nThe rectangle's sides must be positive\n");
  }
}

double chugaynov::Rectangle::getArea() const
{
  return width_ * height_;
}

chugaynov::rectangle_t chugaynov::Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

void chugaynov::Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void chugaynov::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void chugaynov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("\nScaling coefficient must be positive\n");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
