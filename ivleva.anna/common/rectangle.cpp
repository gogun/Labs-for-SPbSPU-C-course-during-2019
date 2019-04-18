#include "rectangle.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>

ivleva::Rectangle::Rectangle(const rectangle_t & rect):
  rect_(rect)
{
  assert((rect.width > 0) && (rect.height > 0));
}

double ivleva::Rectangle::getArea() const
{
  return (rect_.width * rect_.height);
}

ivleva::rectangle_t ivleva::Rectangle::getFrameRect() const
{
  return rect_;
}

void ivleva::Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void ivleva::Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void ivleva::Rectangle::print() const
{
  std::cout << "Area of rectangle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << rect_.width << std::endl;
  std::cout << "Height of frame rectangle: " << rect_.height << std::endl;
  std::cout << "Center point of frame rectangle: (" << rect_.pos.x
  << "; " << rect_.pos.y << ")" << std::endl;
}

void ivleva::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("The coefficient must be positive");
  }
  rect_.width *= coefficient;
  rect_.height *= coefficient;
}
