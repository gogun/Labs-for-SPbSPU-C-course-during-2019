#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

senatova::Rectangle::Rectangle(const point_t pos, double height, double width):
  pos_(pos),
  height_(height),
  width_(width)
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

double senatova::Rectangle::getArea() const
{
  return (width_ * height_);
}

senatova::rectangle_t senatova::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void senatova::Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void senatova::Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void senatova::Rectangle::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Invalid scale multiplier");
  }
  else
  {
    width_ *= multiplier;
    height_ *= multiplier;
  }
}

void senatova::Rectangle::print() const
{
  std::cout << "Area: " << getArea() << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Center position x = " << pos_.x << std::endl;
  std::cout << "Center position y = " << pos_.y << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Rectangle frame: " << std::endl;
  std::cout << "Height: " << frame.height << std::endl;
  std::cout << "Width: " << frame.width << "\n\n";
}
