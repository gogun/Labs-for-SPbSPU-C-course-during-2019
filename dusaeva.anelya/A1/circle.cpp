#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <iostream>
#include "circle.hpp"

Circle::Circle(const point_t &position, double radius):
  position_(position),
  radius_(radius)
{
  assert(radius >= 0);
}

double Circle::getArea() const
{
  return M_PI*pow(radius_, 2);
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_*2, radius_*2, position_};
}

void Circle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

void Circle::move(const point_t &position)
{
  position_ = position;
}

void Circle::printInfo() const
{
  rectangle_t info = getFrameRect();
  std::cout << "Radius = " << radius_ << std::endl;
  std::cout << "Central coordinates (" << position_.x << ", " << position_.y << ")" << std::endl;
  std::cout << "Area = " << getArea() << std::endl;
  std::cout << "Central coordinates of frame: (" << info.pos.x << ", " << info.pos.y << ")" << std::endl;
  std::cout << "Frame width = " << info.width <<", frame height = " << info.height << std::endl;
  std::cout << std::endl;
}

