#include "rectangle.hpp"
#include <iostream>

bublyaev::Rectangle::Rectangle(const point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if ((width_ <= 0) || (height_ <= 0))
  {
    throw std::invalid_argument("Incorrect dimentions");
  }
}

double bublyaev::Rectangle::getArea() const
{
  return width_ * height_;
}

bublyaev::rectangle_t bublyaev::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

double bublyaev::Rectangle::getWidth() const
{
  return width_;
}

double bublyaev::Rectangle::getHeight() const
{
  return height_;
}

void bublyaev::Rectangle::move(const point_t &newPos)
{
  center_ = newPos;
}

void bublyaev::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void bublyaev::Rectangle::scale(double multiplier)
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

void bublyaev::Rectangle::printInfo() const
{
  std::cout << "Rectangle:\nCenter coordinates: (" << center_.x << " , " << center_.y << ")" << std::endl;
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
}
