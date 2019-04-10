#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(const rectangle_t & rect) :
  rect_(rect)
{
  assert((rect_.width>=0.0)and(rect_.height>=0.0));
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

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::print() const
{
  std::cout << "Area of rectangle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << rect_.width << std::endl;
  std::cout << "Height of frame rectangle: " << rect_.height << std::endl;
  std::cout << "Center point of frame rectangle: (" << rect_.pos.x
    << "; " << rect_.pos.y << ")" << std::endl;
}
