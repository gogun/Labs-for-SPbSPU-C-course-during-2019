#include "rectangle.hpp"

#include <stdexcept>

seleznev::Rectangle::Rectangle(double w, double h, point_t p):
  Shape(p),
  width_(w),
  height_(h)
{
  if ((height_ < 0) || (width_ < 0))
    throw std::out_of_range("Height/width is out of range");
}

double seleznev::Rectangle::getArea() const
{
  return width_ * height_;
}

seleznev::rectangle_t seleznev::Rectangle::getFrameRect() const
{
  return {width_, height_, centre_};
}

void seleznev::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::out_of_range("Coefficient is out of range");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

double seleznev::Rectangle::getWidth()
{
  return width_;
}

double seleznev::Rectangle::getHeight()
{
  return height_;
}
