#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(double width, double height, point_t pos):
  options_.width(width),
  options_.height(height),
  options.pos(height)
{
  assert(options_.width > 0.0);
  assert(options_.height > 0.0);
}

double Rectangle::getArea() const
{
  return (options_.width * options_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return options_;
}

void Rectangle::displayData() const
{
  std::cout << "Width: " << options_.width
    << "\nHeight: " << options_.height
    << "\nPosition: (" << options_.pos.x << ';' << options_.pos.y << ')';
}

void Rectangle::move (double dx, double dy)
{
  options_.pos.x += dx;
  options_.pos.y += dy;
}

void Rectangle::move (point_t newPos)
{
  options_.pos = newPos;
}
