#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double width, double height, double x, double y)
{
  parameters_.height = height;
  parameters_.width = width;
  parameters_.pos.x = x;
  parameters_.pos.y = y;
  if (parameters_.width <= 0)
  {
    throw std::invalid_argument("Invalid rectangle width!");
  }
  if (parameters_.height <= 0)
  {
    throw std::invalid_argument("Invalid rectangle height!");
  }
}

rectangle_t Rectangle::getFrameRect() const
{
  return parameters_;
}

double Rectangle::getArea() const
{
  return parameters_.height*parameters_.width;
}

void Rectangle::move(const double dx, const double dy)
{
  parameters_.pos.x += dx;
  parameters_.pos.y += dy;
}

void Rectangle::move(const point_t &point) 
{
  parameters_.pos = point;
}
