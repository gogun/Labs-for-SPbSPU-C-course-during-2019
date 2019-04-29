#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

gusarov::Rectangle::Rectangle(const point_t &center, const double width, const double height):
  center_(center),
  width_(width),
  height_(height)
{
  if(width <= 0 || height <= 0)
  {
    throw std::invalid_argument("Invalid width or height value");
  }
}
double gusarov::Rectangle::getArea() const
{
  return width_ * height_;
}
gusarov::rectangle_t gusarov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}
void gusarov::Rectangle::move(const double shiftX, const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}
void gusarov::Rectangle::move(const gusarov::point_t &newPoint)
{
  center_ = newPoint;
}
void gusarov::Rectangle::printInfo() const
{
  std::cout << "Width of rectangle is " << width_ << '\n';
  std::cout << "Height of rectangle is " << height_ << '\n';
  std::cout << "Center of rectangle is a point: (" << center_.x << ";" << center_.y << ")" << '\n';
}
void gusarov::Rectangle::scale(const double scale)
{
  if(scale <= 0)
  {
    throw std::invalid_argument("Invalid scale value");
  }
  width_ *= scale;
  height_ *= scale;
}
double gusarov::Rectangle::getHeight() const
{
  return height_;
}
double gusarov::Rectangle::getWidth() const
{
  return width_;
}
