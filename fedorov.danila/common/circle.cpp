#include "circle.hpp"

#include <iostream>
#include <stdexcept>

#define _USE_MATH_DEFINES
#include <math.h>

fedorov::Circle::Circle(const point_t &position, const double radius):
  Shape(position),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
}

fedorov::rectangle_t fedorov::Circle::getFrameRect() const
{
  return { position_, radius_ * 2, radius_ * 2 };
}

double fedorov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

double fedorov::Circle::getRadius() const
{
  return radius_;
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
  if (scale <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  radius_ *= scale;
}
