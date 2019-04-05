#include "circle.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const double radius, const point_t & center):
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return (M_PI * pow(radius_, 2));
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_ , 2 * radius_ , center_};
}

void Circle::move(const point_t & cpos)
{
  center_ = cpos;
}

void Circle::move(const double cx, const double cy)
{
  center_.x += cx;
  center_.y += cy;
}

void Circle::printData() const
{
  std::cout << "Circle's area: " << getArea() << std::endl;
  std::cout << "Height of frame: " << getFrameRect().height << std::endl;
  std::cout << "Width of frame: " << getFrameRect().width << std::endl;
  std::cout << "Center of frame: (" << getFrameRect().pos.x
      << ';' << getFrameRect().pos.y << ')' << std::endl;
  std::cout << std::endl;
}
