#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

maschenko::Rectangle::Rectangle(const point_t &center, double width, double height) :
  rectangle_({center, width, height})
{
  if ((rectangle_.width <= 0) || (rectangle_.height <= 0)) {
    throw std::invalid_argument ("Invalid width of height of rectangle.");
  }
}

double maschenko::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

maschenko::rectangle_t maschenko::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void maschenko::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.y += dy;
  rectangle_.pos.x += dx;
}

void maschenko::Rectangle::move(const point_t &center)
{
  rectangle_.pos = center;
}

void maschenko::Rectangle::scale(double coefficient)
{
  if (coefficient > 0)
  {
    rectangle_.height *= coefficient;
    rectangle_.width *= coefficient;
  }
  else
  {
    throw std::invalid_argument ("Invalid coefficient for rectangle");
  }
}

void maschenko::Rectangle::writeInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << std::endl << "Rectangle with center: (" << rectangle_.pos.x
            << ";" << rectangle_.pos.y << ")" << std::endl
            << "Frame rectangle width = " << rectangle.width
            << ", height = " << rectangle.height << std::endl
            << "Area = " << getArea() << std::endl << std::endl;
}

maschenko::rectangle_t maschenko::Rectangle::getRectangle() const
{
  return rectangle_;
}
