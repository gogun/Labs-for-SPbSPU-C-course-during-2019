#include "circle.hpp"

#include <iostream>
#include <cassert>

#define _USE_MATH_DEFINES
#include <math.h>

fedorov::Circle::Circle(const point_t &position, const double radius):
  Shape(position),
  radius_(radius)
{
  assert(radius_ > 0);
}

fedorov::rectangle_t fedorov::Circle::getFrameRect() const
{
  return {position_, radius_ * 2, radius_ * 2};
}

double fedorov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

void fedorov::Circle::printInfo() const
{
  Shape::printInfo();
  std::cout << "\t radius: " << radius_ << std::endl
      << "\t area: " << getArea() << std::endl
      << "\t frame:" << std::endl
      << "\t\tcenter: (" << getFrameRect().pos.x << ";" << getFrameRect().pos.y << ")" << std::endl
      << "\t\twidth: " << getFrameRect().width << "\theight: " << getFrameRect().height << std::endl
      << std::endl;
}

void fedorov::Circle::scale(double scale)
{
	assert(scale > 0);
	radius_ *= scale;
}
