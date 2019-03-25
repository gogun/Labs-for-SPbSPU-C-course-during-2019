#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(rectangle_t characteristics):
  characteristics_(characteristics)
{
  assert((characteristics_.height > 0) && ("Incorrect height value"));
  assert((characteristics_.width > 0) && ("Incorrect width value"));
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
