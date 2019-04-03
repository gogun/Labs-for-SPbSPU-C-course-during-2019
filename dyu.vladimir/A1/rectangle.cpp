#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double width, double height, const point_t & pos):
rect_ (rectangle_t { .width = width, .height = height, .pos = pos })
{
  if (width <= 0.0)
  {
    std::cerr << " Invalid rectangle width, shall be greater than 0.0, is: " << width << std::endl;
  }

  if (height <= 0.0)
  {
    std::cerr << "Invalid rectangle height, shall be greater than 0.0, is: " << height << std::endl;
  }
}

double Rectangle::getArea() const
{
  return(rect_.width * rect_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & pos)
{
  rect_.pos.x = pos.x;
  rect_.pos.y = pos.y;
}

void Rectangle::move(double x, double y)
{
  rect_.pos.x += x;
  rect_.pos.y += y;
}
