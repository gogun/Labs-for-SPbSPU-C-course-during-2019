#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(rectangle_t characteristics):
  characteristics_(characteristics)
{
  if ((characteristics_.height <= 0) || (characteristics_.width <= 0))
  {
    std::cout << "Incorrect values" << std::endl;
    exit(0);
  }
}

double Rectangle::getArea() const
{
  return characteristics_.width * characteristics_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return characteristics_;
}

void Rectangle::move(const point_t &dot)
{
  characteristics_.pos = dot;
}

void Rectangle::move(double deltax, double deltay)
{
  characteristics_.pos.x += deltax;
  characteristics_.pos.y += deltay;
}

void Rectangle::writeChanges() const
{
  std::cout << "New coordinates of the centre (" << characteristics_.pos.x << ","
      << characteristics_.pos.y << ")" << std::endl;
}
