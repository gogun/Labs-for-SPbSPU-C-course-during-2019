#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(const point_t &pos, double w, double h) :
  rectangle_({ pos, w, h })

{
  assert((rectangle_.height > 0) && (rectangle_.width > 0));
}

double Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::getInfo() const
{
  rectangle_t rec_ = getFrameRect();
  std::cout << "Rectangle height = " << rec_.height << std::endl;
  std::cout << "Rectangle width = " << rec_.width << std::endl;
  std::cout << "Point x = " << rec_.pos.x << std::endl;
  std::cout << "Point y = " << rec_.pos.y << std::endl;
}
#endif
