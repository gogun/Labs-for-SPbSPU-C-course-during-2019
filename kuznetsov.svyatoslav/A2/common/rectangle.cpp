#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

kuznetsov::Rectangle::Rectangle(const kuznetsov::point_t &position, double width, double height) :
  width_(width),
  height_(height),
  center_(position)
{
  if(width_ <= 0)
  {
    throw std::invalid_argument("Width must be positive");
  }
  if(height_ <= 0)
  {
    throw std::invalid_argument("Height must be positive");
  }
}

double kuznetsov::Rectangle::getArea() const
{
  return (width_ * height_);
}

kuznetsov::rectangle_t kuznetsov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void kuznetsov::Rectangle::move(const point_t &position)
{
  center_ = position;
}

void kuznetsov::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void kuznetsov::Rectangle::printInfo() const
{
  std::cout << "Information about rectangle: \n";
  std::cout << "Width: " << width_ << "\n";
  std::cout << "Height: " << height_ << "\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ")\n";
  std::cout << "Area of rectangle: " << getArea() << "\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "width: " << frameRectangle.width << "\n";
  std::cout << "height: " << frameRectangle.height << "\n";
  std::cout << "center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ")\n\n";
}

void kuznetsov::Rectangle::scale(double coef)
{
  if(coef <= 0)
  {
    throw std::invalid_argument("Coefficient must be positive");
  }
  width_ *= coef;
  height_ *= coef;
}
