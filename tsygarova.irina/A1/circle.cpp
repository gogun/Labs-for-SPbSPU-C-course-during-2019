#include "circle.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

Circle::Circle(double r, const point_t & position):
  r_(r),
  pos(position)
{
  if (r_ <= 0)
  {
   throw std::invalid_argument("Invalid circle radius");
  }
}

double Circle::getArea() const
{
  return (M_PI * r_ * r_);
}

rectangle_t Circle:: getFrameRect() const
{
  return {2 * r_, 2 * r_, pos};
}

point_t Circle::Center() const
{
  return pos;
}

void Circle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}

void Circle::move(const point_t & p)
{
  pos = p;
}

void Circle::print() const
{
  std::cout << "Area of circle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width_<< std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height_<< std::endl;
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos.x
            << "; " << getFrameRect().pos.y << ")" << std::endl;
}
