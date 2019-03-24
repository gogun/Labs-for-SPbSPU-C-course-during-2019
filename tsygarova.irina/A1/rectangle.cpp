#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(double width, double height, const point_t & position):
  width_(width),
  height_(height),
  pos_(position)
{
  if (width_ <= 0 || height_ <= 0)
  {
   throw std::invalid_argument("Invalid rectangle parameters");
  }
}

double Rectangle:: getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect () const
{
  return {width_, height_, pos_};
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t & p)
{
  pos_ = p;
}

point_t Rectangle::Center() const
{
  return pos_;
}

void Rectangle::print() const
{
  std::cout << "Area of rectangle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width_ << std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height_ << std::endl;
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos_.x
            << "; " << getFrameRect().pos_.y << ")" << std::endl;
}
