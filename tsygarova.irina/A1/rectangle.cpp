#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(double width, double height, const point_t & position):
  width_{width},
  height_{height},
  pos_{position}
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

point_t Rectangle::Center() const
{
    return pos_;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x_ += dx;
  pos_.y_ += dy;
}

void Rectangle::move(const point_t & p)
{
  pos_ = p;
}

void Rectangle::print() const
{
  std::cout << "Area of rectangle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width_ << std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height_ << std::endl;
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos.x_
            << "; " << getFrameRect().pos.y_ << ")" << std::endl;
}
