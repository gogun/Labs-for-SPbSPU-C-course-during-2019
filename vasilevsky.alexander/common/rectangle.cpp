#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

vasilevsky::Rectangle::Rectangle(const double &width, const double &height, const point_t &point):
  width_(width),
  height_(height),
  center_(point)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Width of rectangle must be a positive number");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Height of rectangle must be a positive number");
  }
}

double vasilevsky::Rectangle::getArea() const
{
  return (height_ * width_);
}

vasilevsky::rectangle_t vasilevsky::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void vasilevsky::Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void vasilevsky::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void vasilevsky::Rectangle::printInfo() const
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

void vasilevsky::Rectangle::scale(const double &coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient of scale must be a positive number");
  }
  else
  {
    width_ *= coefficient;
    height_ *= coefficient;
  }
}
