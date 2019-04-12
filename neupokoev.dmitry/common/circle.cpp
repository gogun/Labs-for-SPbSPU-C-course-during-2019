#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

neupokoev::Circle::Circle(const point_t &pos, double radius) :
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0.0) 
  {
    throw std::invalid_argument("Radius must be a positive number");
  }
}

double neupokoev::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

neupokoev::rectangle_t neupokoev::Circle::getFrameRect() const
{
  return {pos_, radius_ * 2, radius_ * 2};
}

void neupokoev::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void neupokoev::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void neupokoev::Circle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Circle scale factor must be a positive nunber");
  }
  else
  {
    radius_ *= scaleFactor;
  }
}

void neupokoev::Circle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Circle radius is (" << radius_
      << ") Centre is (" << pos_.x << ","
      << pos_.y << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
