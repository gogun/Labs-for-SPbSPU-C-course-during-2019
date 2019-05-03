#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

korshunov::Rectangle::Rectangle(const point_t &center, double width, double height):
  rectangle_({center, width, height})
{
  if ((width <= 0.0) || (height <= 0.0))
  {
    throw std::invalid_argument("Width and height should be more 0");
  }
}

double korshunov::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

korshunov::rectangle_t korshunov::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void korshunov::Rectangle::move(const point_t &center)
{
  rectangle_.pos = center;
}

void korshunov::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void korshunov::Rectangle::scale(double scale)
{
  if (scale <= 0.0)
  {
    throw std::invalid_argument("Invalid scale");
  }
  rectangle_.width *= scale;
  rectangle_.height *= scale;
}
