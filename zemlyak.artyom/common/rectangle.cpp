#include "rectangle.hpp"
#include <iostream>
#include <cassert>

zemlyak::Rectangle::Rectangle(const point_t &position, const double width, const double height):
  rect_({position, width, height})
{
  if (width < 0)
  {
    throw std::invalid_argument("The width value of rectangle must be non-negative.");
  }
  if (height < 0)
  {
    throw std::invalid_argument("The height value of rectangle must be non-negative.");
  }
}

double zemlyak::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

zemlyak::rectangle_t zemlyak::Rectangle::getFrameRect() const
{
   return rect_;
}

void zemlyak::Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}

void zemlyak::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void zemlyak::Rectangle::scale(double factor)
{
  if (factor < 0)
  {
    throw std::invalid_argument("The value of the parties of rectangle must be non-negative.");
  }
  else
  {
    rect_.width *= factor;
    rect_.height *= factor;
  }
}

void zemlyak::Rectangle::printInfo() const
{
  zemlyak::rectangle_t FrameRectData = getFrameRect();
  std::cout << "Rectangle:" << std::endl;
  std::cout << "  coordinates (X; Y): (" << rect_.pos.x;
  std::cout << "; " << rect_.pos.y << ")" << std::endl;
  std::cout << "  area: " << getArea() << std::endl;
  std::cout << "  Frame rectangle width: " << FrameRectData.width;
  std::cout << "; height: " << FrameRectData.height << std::endl;
}
