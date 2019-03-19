#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const point_t &center, double width, double height) :
  rectangle_({center, width, height})
{
  if ((rectangle_.width <= 0) || (rectangle_.height <= 0))
  {
    throw "Invalid width or height of rectangle.";
  }
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.center.y += dy;
  rectangle_.center.x += dx;
}

void Rectangle::move(const point_t &centr)
{
  rectangle_.center = centr;
}

void Rectangle::writeInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << std::endl << "Rectangle with center: (" << rectangle_.center.x
            << ";" << rectangle_.center.y << ")" << std::endl
            << "Frame rectangle width = "	<< rectangle.width
            << ", height = " << rectangle.height << std::endl
            << "Area = " << getArea() << std::endl << std::endl;
}
