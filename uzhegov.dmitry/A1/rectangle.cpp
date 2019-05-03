#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}

void Rectangle::printParams() const
{
  std::cout << "-Coordination of the center (" << center_.x << "," << center_.y << ")\n";
  std::cout << "-Width = " << width_ << ", Height = " << height_ << '\n';
  std::cout << "-Area = " << Rectangle::getArea() << '\n';
  rectangle_t frameRect = getFrameRect();
  std::cout << "-Parameters of FrameRect:\n";
  std::cout << "--Coordination of the center (" << frameRect.pos.x << "," << frameRect.pos.y << ")\n";
  std::cout << "--Width = " << frameRect.width << ", Height = " << frameRect.height << '\n';
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &point)
{
  center_ = point;
}
