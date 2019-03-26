#include "rectangle.hpp"

#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t &position, const double wight, const double height) :
  position_(position),
  width_(wight),
  height_(height)
{
  assert((width_ > 0) && (height_ > 0));
}

Rectangle::Rectangle(const double x, const double y, const double wight, const double height) :
  position_({x, y}),
  width_(wight),
  height_(height)
{
  assert((width_ > 0) && (height_ > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{position_, width_, height_};
}

void Rectangle::move(const point_t & position)
{
  position_ = position;
}

void Rectangle::move(const double xx, const double yy)
{
  position_.x += xx;
  position_.y += yy;
}

void Rectangle::printInf() const
{
  std::cout << "Parameters of rectangle:" << std::endl
    << "Position of the center: (" << position_.x << ";" << position_.y << ")" << std::endl
    << "Width and height of the rectangle " << width_ << " , " << height_ << std::endl
    << "Area of the rectangle: " << getArea() << std::endl
    << "Parameters of frame rect of rectangle: " << std::endl
    << "Position of the frame rect: (" << getFrameRect().position.x << ";"
    << getFrameRect().position.y << ")" << std::endl
    << "Width of the frame rect: " << getFrameRect().width << std::endl
    << "Height of the frame rect: " << getFrameRect().height << std::endl << std::endl;
}


