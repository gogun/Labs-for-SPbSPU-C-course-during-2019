#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

skudar::Rectangle::Rectangle(const point_t &position, double width, double height) :
  center_(position),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Width and height must be positive numbers");
  }
}

skudar::Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Width and height must be positive numbers");
  }
}

void skudar::Rectangle::move(point_t point)
{
  center_ = point;
}

void skudar::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

double skudar::Rectangle::getArea() const
{
  return width_ * height_;
}

skudar::rectangle_t skudar::Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}

void skudar::Rectangle::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor must be a non-negative number");
  }
  else
  {
    width_ *= factor;
    height_ *= factor;
  }
}
