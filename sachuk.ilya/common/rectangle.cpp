#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

sachuk::Rectangle::Rectangle(const point_t & point, double w, double h):
  center_(point),
  width_(w),
  height_(h)
{
  if ((width_ <= 0) || (height_ <= 0)) {
    throw std::invalid_argument("Invalid arguments");
  }
}

double sachuk::Rectangle::getArea() const
{
  return width_ * height_;
}

void sachuk::Rectangle::move(const point_t & point)
{
  center_ = point;
}

void sachuk::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

sachuk::rectangle_t sachuk::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void sachuk::Rectangle::scale(const double multiplier)
{
  if (multiplier <= 0) {
    throw std::invalid_argument("Multiplier must be positive");
  } else {
    width_ *= multiplier;
    height_ *= multiplier;
  }
}

void sachuk::Rectangle::printInfo() const
{
  std::cout << "Rectangle:";
  std::cout << " Width=" << getFrameRect().width << ";";
  std::cout << " Height=" << getFrameRect().height << std::endl;
  std::cout << "X=" << getFrameRect().pos.x << ";";
  std::cout << "Y=" << getFrameRect().pos.y << std::endl;
  std::cout << "Area=" << getArea() << std::endl << std::endl;
}
