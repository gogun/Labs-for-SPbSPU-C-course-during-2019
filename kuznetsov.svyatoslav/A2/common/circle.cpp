#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

kuznetsov::Circle::Circle(const kuznetsov::point_t &position, double radius) :
  radius_(radius),
  center_(position)
{
  if(radius_ <= 0)
  {
    throw std::invalid_argument("Radius must be positive");
  }
}

double kuznetsov::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

kuznetsov::rectangle_t kuznetsov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void kuznetsov::Circle::move(const point_t &position)
{
  center_ = position;
}

void kuznetsov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void kuznetsov::Circle::printInfo() const
{
  std::cout << "Information about circle: \n";
  std::cout << "Radius: " << radius_ << "\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ")\n";
  std::cout << "Area of circle: " << getArea() << "\n";
  std::cout << "Frame rectangle: \n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "width: " << frameRectangle.width << "\n";
  std::cout << "height: " << frameRectangle.height << "\n";
  std::cout << "center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ")\n\n";
}

void kuznetsov::Circle::scale(double coef)
{
  if(coef <= 0)
  {
    throw std::invalid_argument("Coefficient must be positive");
  }
  radius_ *= coef;
}
