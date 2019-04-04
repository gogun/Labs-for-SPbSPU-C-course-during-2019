#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center, double width, double height):
    rectangle_({center, width, height})
{
  assert((width > 0.0) && (height > 0.0));
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &center)
{
  rectangle_.pos = center;
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::writeInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Information about the Rectangle: \n";
  std::cout << "Width: " << rectangle.width << "\n";
  std::cout << "Heigth: " << rectangle.height << "\n";
  std::cout << "Center: (" << rectangle.pos.x << "," << rectangle.pos.y << ") \n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle: width = " << rectangle.width << " ,height = " << rectangle.height << std::endl
            << std::endl;
}
