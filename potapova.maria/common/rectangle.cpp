#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

potapova::Rectangle::Rectangle(const point_t &center, double height, double width) :
  rectangle_({center, height, width})
{
  if (height <= 0)
   {
     throw std::invalid_argument("Invalid height");
   }
   if (width <= 0)
   {
     throw std::invalid_argument("Invalid width");
   }
}

double potapova::Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

void potapova::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void potapova::Rectangle::move(const point_t &center)
{
  rectangle_.pos = center;
}

potapova::rectangle_t potapova::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void potapova::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  rectangle_.height *= coefficient;
  rectangle_.width *= coefficient;
}
