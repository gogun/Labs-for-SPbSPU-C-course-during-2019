#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>

shestakova::Rectangle::Rectangle(point_t pos, double w, double h) :
  pos_(pos),
  width_(w),
  height_(h)
{
  if (height_ <= 0)
  {
    throw std::invalid_argument("Height can't be negative");
  }
  if (width_ <= 0)
  {
    throw std::invalid_argument("Width can't be negative");
  }
}

double shestakova::Rectangle::getArea() const
{
  return width_ * height_;
}

shestakova::rectangle_t shestakova::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void shestakova::Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void shestakova::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void shestakova::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be negative.");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
