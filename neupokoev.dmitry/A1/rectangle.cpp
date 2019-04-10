#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t &parameters) :
  rect_(parameters)
{
  assert((rect_.height > 0) && (rect_.width > 0));
}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle centre is (" << rect_.pos.x << ","
      << rect_.pos.y << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
