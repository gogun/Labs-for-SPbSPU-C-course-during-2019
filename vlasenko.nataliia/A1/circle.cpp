#define _USE_MATH_DEFINES

#include "circle.hpp"

#include <cassert>
#include <math.h>
#include <iostream>

Circle::Circle(const point_t &position, const double radius):
  radius_(radius),
    center_(position)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, center_ };
}

void Circle::printInfo() const
{
  std::cout << "\t Information about circle:\n";
  std::cout << "\t Radius: " << radius_ << " \n";
  std::cout << "\t Area of circle: " << getArea() << " \n";
  std::cout << "\t Center: (" << center_.x << "," << center_.y << "). \n";
  std::cout << "\t Frame rectangle:" << " \n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "\t Polymorphism: \n";
  std::cout << "\t Width: " << frameRectangle.width << "\n";
  std::cout << "\t Height: " << frameRectangle.height << "\n";
  std::cout << "\t Center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ").\n\n";
}

void Circle::move(const point_t &position)
{
  center_ = position;
}

void Circle::move(const double &shift_x, const double &shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}
