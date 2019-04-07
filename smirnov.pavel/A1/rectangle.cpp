#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(double width, double
      heigth, const point_t & center):
  width_(width),
  heigth_(heigth),
  center_(center)
{
  assert((width_ > 0) && (heigth_ > 0));
}

double Rectangle::getArea() const
{
  return width_ * heigth_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, heigth_, center_ };
}

void Rectangle::move(const point_t & new_point)
{
  center_ = new_point;
}

void Rectangle::move(double x_delta, double y_delta)
{
  center_.x += x_delta;
  center_.y += y_delta;
}

void Rectangle::getInfo() const
{
  std::cout << "Area of rectangle is "
      << getArea() << "\n";
	std::cout << "Width of rectangle is "
      << width_ << "\n";
	std::cout << "Heigth of rectangle is "
      << heigth_ << "\n";
	std::cout << "Center of rectangle is ("
      << center_.x << ";" << center_.y << ")\n";
}
