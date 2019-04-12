#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

lukina::Rectangle::Rectangle(const point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Rectangle parameters must be positive!\n");
  }
}

double lukina::Rectangle::getArea() const
{
  return (width_ * height_);
}

lukina::rectangle_t lukina::Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}

void lukina::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void lukina::Rectangle::move(const point_t &newPoint)
{
  center_ = newPoint;
}

void lukina::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient should be positive!\n");
  }
  else
  {
    width_ *= coefficient;
    height_ *= coefficient;
  }
}

void lukina::Rectangle::printInfo() const
{
  std::cout << "Center: " << center_.x << ", " << center_.y << std::endl;
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Rectangle area: " << getArea() << std::endl;
  std::cout << "Frame rectangle:" << std::endl;
  std::cout << "-Center: " << getFrameRect().pos.x << ", " << getFrameRect().pos.y << std::endl;
  std::cout << "-Width: " << getFrameRect().width << std::endl;
  std::cout << "-Height: " << getFrameRect().height << std::endl;
  std::cout << std::endl;
}
