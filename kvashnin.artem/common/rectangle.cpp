#include "rectangle.hpp"
#include <iostream>

kvashnin::Rectangle::Rectangle(const point_t &position, const double width, const double height):
  rect_({position, width, height})
{
  if (width < 0 || height < 0)
  {
    throw std::invalid_argument("width or height can not be < 0");
  }
}

double kvashnin::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

kvashnin::rectangle_t kvashnin::Rectangle::getFrameRect() const
{
  return rect_;
}

void kvashnin::Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}

void kvashnin::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void kvashnin::Rectangle::scale(double coefficient)
{
  if(coefficient <= 0)
  {
    throw std::invalid_argument("coefficient can not be <= 0");
  }
  rect_.height *= coefficient;
  rect_.width *= coefficient;
}

void kvashnin::Rectangle::printInfo() const
{
  rectangle_t FrameRectData = getFrameRect();
  std::cout << "Rectangle coordinates: X: " << rect_.pos.x
      << "; Y: " << rect_.pos.y << std::endl
      << "Rectangle area: " << getArea() << std::endl
      << "Rectangle frame width: " << FrameRectData.width
      << "; height: " << FrameRectData.height << std::endl;
}
