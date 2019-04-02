#include "circle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Circle::Circle(const double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0);
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, pos_ };
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}


void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(point_t newpos)
{
  pos_ = newpos;
}

void Circle::getInfo() const
{
  std::cout << "Circle with radius: " << radius_
            << ", centre at point: (" << pos_.x << ";"
            << pos_.y << ")" << std::endl;
  std::cout << "Circle area: " << getArea() << std::endl;
  std::cout << "Frame width: " << getFrameRect().width
            << ", height: " << getFrameRect().height
            << ", centre: (" << getFrameRect().pos.x << ";"
            << getFrameRect().pos.y << ")" << std::endl;
  std::cout << "* * *" << std::endl;
}
