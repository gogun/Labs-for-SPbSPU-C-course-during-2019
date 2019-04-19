#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

akhmedov::Rectangle::Rectangle(const point_t &pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Arguments width and height are surely invalid");
  }
}

double akhmedov::Rectangle::getArea() const
{
  return width_ * height_;
}

akhmedov::rectangle_t akhmedov::Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

void akhmedov::Rectangle::move(const point_t &pos)
{
  pos_ = pos;
}

void akhmedov::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void akhmedov::Rectangle::printInfo() const
{
  std::cout << "X center is: " << pos_.x << std::endl;
  std::cout << "Y center is: " << pos_.y << std::endl;
  std::cout << "Width is: " << width_ << std::endl;
  std::cout << "Height is: " << height_ << std::endl;
}

akhmedov::point_t akhmedov::Rectangle::getCenter() const
{
  return pos_;
}

void akhmedov::Rectangle::scale(double multiplyCoefficient)
{
  if (multiplyCoefficient <= 0)
  {
    throw std::invalid_argument("Multiply Coefficient is surely invalid");
  }
  width_ *= multiplyCoefficient;
  height_ *= multiplyCoefficient;
}

double akhmedov::Rectangle::getWidth() const
{
  return width_;
}

double akhmedov::Rectangle::getHeight() const
{
  return height_;
}
