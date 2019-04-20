#include "rectangle.hpp"

#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t & rect):
  rect_(rect)
{
  assert((rect_.width > 0.0) && (rect_.height > 0.0));
}

double Rectangle::getArea() const
{
  return (rect_.width * rect_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::show() const
{
  std::cout << "Area: " << getArea() << std::endl;
  std::cout << "Width: " << rect_.width << std::endl;
  std::cout << "Height: " << rect_.height << std::endl;
  std::cout << "Center coordinates: (" << rect_.pos.x
      << "; " << rect_.pos.y << ")" << std::endl;
}
