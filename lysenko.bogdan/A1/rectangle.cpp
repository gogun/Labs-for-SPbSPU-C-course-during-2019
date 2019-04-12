#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t & rect):
  rect_(rect)
{
  assert((rect_.width > 0) && ("Error. Incorrect width of rectangle."));
  assert((rect_.height > 0) && ("Error. Incorrect height of rectangle."));
}

double Rectangle::getArea() const
{
  return (rect_.height * rect_.width);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::print() const 
{
  std::cout << "Area of rectangle: " << getArea() << "\n";
  std::cout << "Width of frame rectangle: " << rect_.width << "\n";
  std::cout << "Height of frame rectangle: " << rect_.height << "\n";
  std::cout << "Center point of frame rectangle: (" << rect_.pos.x
            << "; " << rect_.pos.y << ")" << "\n";
}
