#include <cassert>
#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &position, const double width, const double height) :
    pos_(position),
    width_(width),
    height_(height)
{
  assert(width > 0 && height > 0);
}

Rectangle::Rectangle(const rectangle_t &info) :
    pos_(info.pos),
    width_(info.width),
    height_(info.height)
{
  assert(width_ > 0 && height_ > 0);
}

Rectangle::Rectangle() :
    pos_({0, 0}),
    width_(1),
    height_(1) {}

double Rectangle::getArea() const {
  return width_ * height_;
}

void Rectangle::writeInfo() const {
  std::cout << "Rectangle info:\n"
            << "Width - " << width_ << "\n"
            << "Height - " << height_ << "\n"
            << "Center position: x = " << pos_.x << ", y = " << pos_.y << "\n"
            << "Area - " << getArea() << "\n\n";
}

rectangle_t Rectangle::getFrameRect() const {
  return {pos_, width_, height_};
}

void Rectangle::move(const point_t &pos) {
  pos_ = pos;
}

void Rectangle::move(const double dx, const double dy) {
  pos_.x += dx;
  pos_.y += dy;
}
