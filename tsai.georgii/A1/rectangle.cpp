#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &pos, const double &width, const double &height) :
  pos_(pos),
  width_(width),
  height_(height)
{
  assert((width_ >= 0.0) && (height >= 0.0));
  std::cout << "Rectangle was created\n\n";
}

double Rectangle::getArea()const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

void Rectangle::printInfo() const
{
  rectangle_t framingRect = getFrameRect();
  std::cout << "Information about rectangle: \n" << "Width:" << width_ << "\n"
    << "Height: " << height_ << "\n" << "Area: " << getArea() << "\n\n"
    << "Rectangle is at: { " << "x: " << pos_.x << ", y: " << pos_.y << " }\n\n"
    << "Information about framing rectangle:\n" << "Width:" << framingRect.width << "\n"
    << "Height: " << framingRect.height << "\n" << "Center : { " << "x: " << framingRect.pos.x
    << ", y: " << framingRect.pos.y << " }\n\n";
}

void Rectangle::move(const double &dx, const double &dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t &pos)
{
  pos_ = pos;
}
