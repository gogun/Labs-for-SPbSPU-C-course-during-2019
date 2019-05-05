#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

uzhegov::Rectangle::Rectangle(const point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if (width <= 0)
  {
    throw std::invalid_argument("Width should be positive");
  }
  if (height <= 0)
  {
    throw std::invalid_argument("Height should be positive");
  }
}

double uzhegov::Rectangle::getArea() const
{
  return width_ * height_;
}

uzhegov::rectangle_t uzhegov::Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}

void uzhegov::Rectangle::printParams() const
{
  std::cout << "-Coordination of the center (" << center_.x << ", " << center_.y << ")\n";
  std::cout << "-Width = " << width_ << ", Height = " << height_ << '\n';
  std::cout << "-Area = " << getArea() << '\n';
  uzhegov::rectangle_t frameRect = getFrameRect();
  std::cout << "-Parameters of FrameRect:\n";
  std::cout << "--Coordination of the center (" << frameRect.pos.x << ", " << frameRect.pos.y << ")\n";
  std::cout << "--Width = " << frameRect.width << ", Height = " << frameRect.height << '\n';
}

void uzhegov::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void uzhegov::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void uzhegov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient should be positive");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
