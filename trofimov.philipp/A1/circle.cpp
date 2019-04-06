#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert> 

Circle::Circle(const point_t &pos, double r) :
  center_(pos),
  radius_(r)
{
  assert(radius_ >= 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { center_, 2 * radius_, 2 * radius_ };
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::getInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle height = " << rectangle.height << std::endl;
  std::cout << "Rectangle width = " << rectangle.width << std::endl;
  std::cout << "Point x = " << rectangle.pos.x << std::endl;
  std::cout << "Point y = " << rectangle.pos.y << std::endl;
}
