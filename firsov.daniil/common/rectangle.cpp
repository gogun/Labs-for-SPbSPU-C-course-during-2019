#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

firsov::Rectangle::Rectangle(double width, double height, const point_t position):
  width_(width),
  height_(height),
  pos_(position)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Wrong rectangle width");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Wrong rectangle height");
  }
}

double firsov::Rectangle::getArea() const
{
  return (width_ * height_);
}

firsov::rectangle_t firsov::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void firsov::Rectangle::move(const point_t& point)
{
  pos_ = point;
}

void firsov::Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void firsov::Rectangle::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Zoom factor must be positive");
  }
  else
  {
    width_ *= multiplier;
    height_ *= multiplier;
  }
}

void firsov::Rectangle::printShapeInfo() const
{
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Center position: x = " << pos_.x << ", y = " << pos_.y << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Rectangle frame: " << std::endl;
  std::cout << "Width: " << frame.width << std::endl;
  std::cout << "Height: " << frame.height << "\n\n";

}
