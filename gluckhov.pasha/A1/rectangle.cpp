#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t pos):
  options_.width(width),
  options_.height(height),
  options.pos(height)
{}

double Rectangle::getArea() const
{
  return (options_.width * options_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frameRect = {options_.width, options_.height, {options_.pos.x, options_.pos.y}};
  return frameRect;
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
