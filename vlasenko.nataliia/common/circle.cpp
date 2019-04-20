#define _USE_MATH_DEFINES

#include "circle.hpp"

#include <iostream>
#include <stdexcept>
#include <math.h>

vlasenko::Circle::Circle(const vlasenko::point_t &position, const double &radius)://const double radius
  radius_(radius),
  center_(position)
{
    if (radius_ <= 0)
    {
      throw std::invalid_argument("Need a positive value of radius");
    }
}

double vlasenko::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

vlasenko::rectangle_t vlasenko::Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, center_ };
}

void vlasenko::Circle::printInfo() const
{
  std::cout << "\t Information about circle:\n";
  std::cout << "\t Radius: " << radius_ << " \n";
  std::cout << "\t Area of circle: " << getArea() << " \n";
  std::cout << "\t Center: (" << center_.x << "," << center_.y << "). \n";
  std::cout << "\t Frame rectangle:" << " \n";
  vlasenko::rectangle_t frameRectangle = getFrameRect();
  std::cout << "\t Polymorphism: \n";
  std::cout << "\t Width: " << frameRectangle.width << "\n";
  std::cout << "\t Height: " << frameRectangle.height << "\n";
  std::cout << "\t Center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ").\n\n";
}

void vlasenko::Circle::move(const point_t &position)
{
  center_ = position;
}

void vlasenko::Circle::move(const double &shift_x, const double &shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void vlasenko::Circle::scale(double value)
{
  if (value <= 0)
  {
    throw std::invalid_argument("Need a positive value");
  }
  radius_ *= value;
}
