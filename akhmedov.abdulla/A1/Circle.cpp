#include "Circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle() :
  pos_({0, 0}),
  radius_(1)
{
}

Circle::Circle(point_t pos, double radius) :
  pos_(pos),
  radius_(radius)
{
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void Circle::move(point_t pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x = pos_.x + dx;
  pos_.y = pos_.y + dy;
}

void Circle::getInfo() const
{
  std::cout << "X center is: " << pos_.x << std::endl;
  std::cout << "Y center is: " << pos_.y << std::endl;
  std::cout << "Radius is: " << radius_ << std::endl;
}
