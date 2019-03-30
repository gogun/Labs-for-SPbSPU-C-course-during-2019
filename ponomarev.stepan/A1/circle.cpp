#define _USE_MATH_DEFINES
#include "circle.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t pos, double radius):
  pos_(pos),
  radius_(radius)
{
  assert(radius >= 0.0);
}

void Circle::move(const point_t &new_pos)
{
  pos_ = new_pos;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRate() const
{
  return rectangle_t {
    pos_,
    radius_ * 2,
    radius_ * 2,
  };
}

void Circle::info() const
{
  std::cout << "--------------------------" << std::endl;
  std::cout << "Centre:\n" << "x = " << pos_.x << " y = " << pos_.y << std::endl;
  std::cout << "Radius = " << radius_ << std::endl;

  rectangle_t rectangle = getFrameRate();
  std::cout << "Out rectangle:\n" << "Width = " << rectangle.width << "\n" << "Height = " << rectangle.height << "\n"
      << "Centre: " << "x = " << rectangle.pos.x << " y = " << rectangle.pos.y << std::endl;

  std::cout << "Area : " << getArea() << std::endl;
  std::cout << "--------------------------" << std::endl;
}
