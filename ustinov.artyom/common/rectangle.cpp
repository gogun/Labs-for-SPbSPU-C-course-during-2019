#include "rectangle.hpp"
#include <iostream>
#include <cassert>

ustinov::Rectangle::Rectangle(const point_t &center, double width, double height):
  rect_({center, width, height})
{
  if ((rect_.width <= 0) || (rect_.height <= 0))
  {
    throw std::invalid_argument("Invalid width of height of rectangle.");
  }
}

double ustinov::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

ustinov::rectangle_t ustinov::Rectangle::getFrameRect() const
{
  return rect_;
}

void ustinov::Rectangle::move(const point_t &goal)
{
  rect_.pos = goal;
}

void ustinov::Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void ustinov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient for circle");
  }
  else
  {
    rect_.height *= coefficient;
    rect_.width *= coefficient;
  }
}

void ustinov::Rectangle::show() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << std::endl
            << "Coordinates of centre Rect :(" << rect_.pos.x
            << ";" << rect_.pos.y << ")" << std::endl
            << "Frame rectangle width = " << rectangle.width
            << ", height = " << rectangle.height << std::endl
            << "Area = " << getArea() << std::endl;
}
