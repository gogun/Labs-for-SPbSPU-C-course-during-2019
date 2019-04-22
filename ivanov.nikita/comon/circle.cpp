#include "circle.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

ivanov::Circle::Circle(const double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
	throw std::invalid_argument("Error. Incorrect radius of circle");
  }
}

double ivanov::Circle::getArea() const
{
  return (radius_ * radius_ * M_PI);
}

ivanov::rectangle_t ivanov::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void ivanov::Circle::move(const point_t &point)
{
  center_ = point;
}

void ivanov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void ivanov::Circle::draw() const
{ 
  std::cout << "Width of frame rectangle: " << getFrameRect().width << "\n";
  std::cout << "Height of frame rectangle: " << getFrameRect().height << "\n";
  std::cout << "Area of circle: " << getArea() << "\n";
  std::cout << "Center of frame rectangle: (" << getFrameRect().pos.x
            << "; " << getFrameRect().pos.y << ")" << "\n";
}

void ivanov::Circle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient of scale.");
  }
  else
  {
    radius_ *= coefficient;
  }
}
