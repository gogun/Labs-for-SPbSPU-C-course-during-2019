#include "rectangle.hpp"

#include <iostream>
#include <cassert>

Rectangle::Rectangle(const double &width, const double &height, const point_t &point):
  width_(width),
  height_(height),
  center_(point)
{
  assert((height_ > 0.0) && (width_ > 0.0));
}

double Rectangle::getArea() const
{
  return (height_ * width_);
}

void Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &point)
{
  center_ = point;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::printInfo() const
{
  std::cout << "--- RECTANGLE --- \n";
  std::cout << "Width is: " << width_ << "\n";
  std::cout << "Height is: " << height_ << "\n";
  std::cout << "Center point on OX: " << center_.x << "\n";
  std::cout << "Center point on OY: " << center_.y << "\n";
  std::cout << "Area of rectangle is: " << getArea() << "\n";
  std::cout << "--- FRAME --- \n";
  std::cout << "Width is: " << getFrameRect().width << "\n";
  std::cout << "Height is: " << getFrameRect().height << "\n";
  std::cout << "Center point on OX: " << getFrameRect().pos.x << "\n";
  std::cout << "Center point on OY: " << getFrameRect().pos.y << "\n\n";
}
