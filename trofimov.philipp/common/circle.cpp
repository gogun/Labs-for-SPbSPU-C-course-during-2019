#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert> 

trofimov::Circle::Circle(const point_t &pos, double r) :
  center_(pos),
  radius_(r)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Not positive parametrs");
  }
}

double trofimov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

trofimov::rectangle_t trofimov::Circle::getFrameRect() const
{
  return { center_, 2 * radius_, 2 * radius_ };
}

void trofimov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void trofimov::Circle::move(const point_t &point)
{
  center_ = point;
}

void trofimov::Circle::getInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle height = " << rectangle.height << std::endl;
  std::cout << "Rectangle width = " << rectangle.width << std::endl;
  std::cout << "Point x = " << rectangle.pos.x << std::endl;
  std::cout << "Point y = " << rectangle.pos.y << std::endl;
}

void trofimov::Circle::scale(double cScaling)
{
  if (cScaling <= 0)
  {
    throw std::invalid_argument("Not positive parametrs");
  }
  radius_ *= cScaling;
}
