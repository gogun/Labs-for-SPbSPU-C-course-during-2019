#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(const point_t &centre, const double &width, const double &height) :
  Shape(centre),
  width_(width),
  height_(height)
{
  if (width <= 0 || height <= 0)
  {
    throw std::invalid_argument("width <= 0 or height <= 0");
  }
}
void Rectangle::setWidth(const double &width)
{
  if (width <= 0)
  {
    throw std::invalid_argument("width <= 0");
  }
  width_ = width;
}
void Rectangle::setHeight(const double &height)
{
  if (height <= 0)
  {
    throw std::invalid_argument("height <= 0");
  }
  height_ = height;
}
double Rectangle::getWidth() const
{
  return width_;
}
double Rectangle::getHeight() const
{
  return height_;
}
double Rectangle::getArea() const
{
  return (width_ * height_);
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{ width_, height_, pos_ };
}
void Rectangle::move(const point_t &to_position)
{
  pos_ = to_position;
}
void Rectangle::move(const double &dx, const double &dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void Rectangle::printShapeInfo() const
{
  std::cout << "Rectangle info" << "\n";
  std::cout << "Centre is in " << " X= " << pos_.x << " Y= " << pos_.y << "\n";
  std::cout << "Width is= " << width_ << " Height is= " << height_ << "\n";
}
