#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &pos, const double height, const double width) :
    rect_{pos, width, height}
{
  assert(height > 0);
  assert(width > 0);
}

double Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::move(const point_t &point)
{
  rect_.pos = point;
}

point_t Rectangle::getCenter() const
{
  return rect_.pos;
}

void Rectangle::show() const
{
  std::cout << "[Rectangle]: \n";
  std::cout << "Center : (" << getCenter().x << ", " << getCenter().y << ")\n";
  std::cout << "Height : " << getFrameRect().height << "\n";
  std::cout << "Width  : " << getFrameRect().width << "\n";
  std::cout << "Area   : " << getArea() << "\n";
}
