#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const point_t & point, double rad):
  center_(point),
  radius_(rad)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

void Circle::move(const point_t & point)
{
  center_ = point;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::printInfo() const
{
  std::cout << "Circle:" << std::endl;
  std::cout << "Radius:" << radius_ << std::endl;
  std::cout << "X=" << center_.x << ";";
  std::cout << "Y=" << center_.y << std::endl;
  std::cout << "Area=" << getArea() << std::endl;
  std::cout << "Frame Rect:" << std::endl;
  std::cout << "Width" << getFrameRect().width << ";";
  std::cout << "Height" << getFrameRect().height << std::endl;
  std::cout << "X=" << getFrameRect().pos.x << ";";
  std::cout << "Y=" << getFrameRect().pos.y << std::endl << std::endl;
}
