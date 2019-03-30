#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &position, const double &width, const double &height) :
  width_(width),
  height_(height),
  center_(position)
{
  assert((width_ > 0) && (height_ > 0));
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t &position)
{
  center_ = position;
}

void Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::printInfo() const
{
  std::cout << "Information about rectangle: \n";
  std::cout << "Width: " << width_ << "\n";
  std::cout << "Height: " << height_ << "\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ")\n";
  std::cout << "Area of rectangle: " << getArea() << "\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "width: " << frameRectangle.width << "\n";
  std::cout << "height: " << frameRectangle.height << "\n";
  std::cout << "center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ")\n\n";
}