#include "Rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center, double width, double height):
    rectangle_({center, width, height})
{
  assert((width > 0.0) && (height > 0.0));
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.center_.x_ += dx;
  rectangle_.center_.y_ += dy;
}

void Rectangle::move(const point_t &center)
{
  rectangle_.center_ = center;
}

double Rectangle::getArea() const
{
  return rectangle_.width_ * rectangle_.heigth_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::writeInfo() const
{
  rectangle_t rectangleExp = getFrameRect();
  std::cout << "Information about the Rectangle: \n";
  std::cout << "Width: " << rectangleExp.width_ << "\n";
  std::cout << "Heigth: " << rectangleExp.heigth_ << "\n";
  std::cout << "Center: (" << rectangleExp.center_.x_ << "," << rectangleExp.center_.y_ << ") \n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle: width = " << rectangleExp.width_ << " ,heigth = " << rectangleExp.heigth_ << std::endl
            << std::endl;
}
