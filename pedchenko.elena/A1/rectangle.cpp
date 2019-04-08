#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t & center, double width, double height):
  rectangle_({center, width, height})
{
  assert((height > 0.0) && (width > 0.0));
}

double Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}


void Rectangle::move(const point_t & center)
{
  rectangle_.pos = center;
}

void Rectangle::writeInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle: \n";
  std::cout << "1) Center: (" << rectangle.pos.x << "," << rectangle.pos.y << ") \n";
  std::cout << "2) Width: " << rectangle.width << "\n";
  std::cout << "3) Heigth: " << rectangle.height << "\n";
  std::cout << "4) Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle: width = " << rectangle.width << " ,height = " << rectangle.height << "\n"
            << std::endl;
}
