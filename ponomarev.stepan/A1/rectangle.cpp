#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &new_pos, const double width,
    const double height):
  rectangle_({new_pos, width, height})
{
  assert((width > 0.0) && (height > 0.0));
}

void Rectangle::move(const double dx, const double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &new_pos)
{
  rectangle_.pos = new_pos;
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRate() const
{
  return rectangle_;
}

void Rectangle::getInfo() const
{

  rectangle_t rectangle = getFrameRate();
  std::cout << "--------------------------" << std::endl;
  std::cout << "Centre:\n" << "x = " << rectangle.pos.x << " " << "y = "
      << rectangle.pos.y << std::endl;

  std::cout << "Side:\n" << "Width = " << rectangle.width << "\n" << "Height = "
      << rectangle.height << std::endl;

  std::cout << "Area : " << getArea() << std::endl;
  std::cout << "--------------------------" << std::endl;
}
