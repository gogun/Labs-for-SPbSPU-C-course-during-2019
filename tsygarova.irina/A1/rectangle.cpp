#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(double width, double height, const point_t & position):
rect_({width, height, position})
{
  if (width <= 0 || height <= 0)
  {
   throw std::invalid_argument("Invalid rectangle parameters");
  }
}

double Rectangle:: getArea() const
{
  return rect_.width_ * rect_.height_;
}

rectangle_t Rectangle::getFrameRect () const
{
  return rect_;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos.x_ += dx;
  rect_.pos.y_ += dy;
}

void Rectangle::move(const point_t & p)
{
  rect_.pos = p;
}

void Rectangle::print() const
{
  std::cout << "Area of rectangle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << rect_.width_ << std::endl;
  std::cout << "Height of frame rectangle: " << rect_.height_ << std::endl;
  std::cout << "Center point of frame rectangle: (" << rect_.pos.x_
            << "; " << rect_.pos.y_ << ")" << std::endl;
}
