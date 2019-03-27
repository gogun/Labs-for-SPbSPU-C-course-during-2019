#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(point_t pos, double w, double h) :
    pos_(pos),
    width_(w),
    height_(h)
{
    assert((width_ > 0) && (height_ > 0));
}

double Rectangle::getArea() const
{
    return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(point_t point)
{
    pos_ = point;
}

void Rectangle::move(double dx, double dy)
{
    pos_.x += dx;
    pos_.y +=dy;
}

void Rectangle::printInfo() const
{
    rectangle_t rectangle = getFrameRect();
    std::cout << "Rectangle's center (" << rectangle.pos.x
              << "," << rectangle.pos.y << ")\n"
              << "Width = " << rectangle.width
              << ";\nHeight = " << rectangle.height
              << ";\nArea = " << getArea() << "\n";
}
