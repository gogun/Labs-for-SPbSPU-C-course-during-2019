#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert> 

troshev::Circle::Circle(const point_t &pos, double r) :
  center_(pos),
  radius_(r)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Not positive parametrs");
  }
}

double troshev::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

troshev::rectangle_t Circle::getFrameRect() const
{
  return  { center_, 2 * radius_,2 * radius_ };
}

troshev::void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void troshev::Circle::move(const point_t &point)
{
  center_ = point;
}

void troshev::Circle::getInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Point x : " << rectangle.pos.x << std::endl;
  std::cout << "Point y : " << rectangle.pos.y << std::endl;
  std::cout << "Rectangle height : " << rectangle.height << std::endl;
  std::cout << "Rectangle width : " << rectangle.width << std::endl;
}

void troshev::Circle::scale(double number)
{
  if (number <= 0)
  {
    throw std::invalid_argument("Not positive parametrs");
  }
  radius_ *= number;
}
