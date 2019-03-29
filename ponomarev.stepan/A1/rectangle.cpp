#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(point_t &new_pos, double width,
    double heigth):
  rectangle_({new_pospos, width, heigth})
{
  if (width <= 0) || (heigth <= 0) {
    std::cerr << "Invalid parameters." << std::endl;
  }
}

void Rectangle::move(const double dx, const double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &new_pos)
{
  rectangle.pos = new_pos;
}

double Rectangle::getArea() const
{
  return width_ * heigth_;
}

double Rectangle::getFrameRate() const
{
  return rectangle_;
}

void Rectangle::info() const
{
  std::cout << "Centre:\n" << "x = " << rectangle_.pos.x << "\n" << "y = " << rectangle_.pos.y << std::endl;

  std::cout << "Side:\n" << "Width = " << rectangle_.width << "\n" << "Height = " << rectangle_.heigth << std::endl;

  std::count << "Area : " << getArea() << std::endl;
}
