#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(double width, double height, const point_t &newPos) :
  options_({ width, height, newPos })
{
  assert(width > 0.0);
  assert(height > 0.0);
}

double Rectangle::getArea() const
{
  return (options_.width * options_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return options_;
}

void Rectangle::printData() const
{
  std::cout << "Width: " << options_.width << "\tHeight: " << options_.height;
  std::cout << "\nPosition: (" << options_.pos.x << ';' << options_.pos.y << ')';
}

void Rectangle::move(double dx, double dy)
{
  options_.pos.x += dx;
  options_.pos.y += dy;
}

void Rectangle::move(const point_t &newPos)
{
  options_.pos = newPos;
}
