#include <stdexcept>
#include "../include/rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t pos)
{
  if (width <= 0)
    throw std::out_of_range("Width is out of range");

  if (height <= 0)
    throw std::out_of_range("Height is out of range");

  this->width = width;
  this->height = height;
  this->centre = pos;
}

double Rectangle::getArea()
{
  return this->width * height;
}

rectangle_t Rectangle::getFrameRect()
{
    return rectangle_t(this->width, this->height, centre);
}