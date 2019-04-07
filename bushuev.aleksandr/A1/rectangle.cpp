#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center,const double width,const double height) :
  rect_({width,height,center})
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return rect_.width*rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const double x,const double y)
{
  rect_.pos.x+=x;
  rect_.pos.y+=y;
}

void Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}

void Rectangle::printInfo() const
{
  std::cout << "Rectangle at " << "("<< rect_.pos.x << "," << rect_.pos.y << ")" << std::endl;
  std::cout << "Width: " << rect_.width << ", " << "height: " << rect_.height << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
}
