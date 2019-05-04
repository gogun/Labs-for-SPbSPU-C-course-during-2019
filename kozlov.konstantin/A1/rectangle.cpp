#include "rectangle.hpp"

#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t &rect):
  rect_(rect)
{
  assert((rect_.height > 0) && (rect_.width > 0));
}

double Rectangle::getArea() const
{
  return (rect_.height * rect_.width);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const double rx, const double ry)
{
  rect_.pos.x += rx;
  rect_.pos.y += ry;
}

void Rectangle::move(const point_t & rpos)
{
  rect_.pos = rpos;
}

void Rectangle::printData() const
{
  std::cout << "Rectangle's area: " << getArea() << std::endl;
  std::cout << "Height of frame: " << getFrameRect().height << std::endl;
  std::cout << "Width of frame: " << getFrameRect().width << std::endl;
  std::cout << "Center of frame: (" << getFrameRect().pos.x
      << ';' << getFrameRect().pos.y << ')' << std::endl;
  std::cout << std::endl;
}
