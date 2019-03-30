#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const point_t &new_pos, double width,
    double heigth):
  rectangle_({new_pos, width, heigth})
{
  if (width <= 0) {
    std::cerr << "Invalid width." << std::endl;
  }
  if (heigth <= 0) {
    std::cerr << "Invalid heigth." << std::endl;
  }
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
  return rectangle_.width * rectangle_.heigth;
}

rectangle_t Rectangle::getFrameRate() const
{
  return rectangle_;
}

void Rectangle::info() const
{

  rectangle_t rectangle = getFrameRate();
  std::cout << "--------------------------" << std::endl;
  std::cout << "Centre:\n" << "x = " << rectangle.pos.x << " " << "y = "
      << rectangle.pos.y << std::endl;

  std::cout << "Side:\n" << "Width = " << rectangle.width << "\n" << "Height = "
      << rectangle.heigth << std::endl;

  std::cout << "Area : " << getArea() << std::endl;
  std::cout << "--------------------------" << std::endl;
}
