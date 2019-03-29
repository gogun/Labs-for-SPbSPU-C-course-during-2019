#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle(double radius, const point_t pos):
  radius_(radius),
  pos_(pos)
{
  if (radius <= 0) {
    std::cerr << "Invalid radius" << std::endl;
  }
}

void Circle::move(const pos_t &new_pos)
{
  pos_ = new_pos;
}

void Circle::move(const doble dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

double Circle::getArea() const
{
  return M_PI * (radius_ * radius_);
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
  std::cout << "Centre:\n" << "x = " << pos_.x << "\n" << "y = " << pos_.y << std::endl;

  std::cout << "Out rectangle:\n" << "Width = " << getFrameRate.width << "\n" << "Height = " << getFrameRate.heigth << "\n"\
      << "Centre: " << "x = " << getFrameRate.pos.x << "\n" << "y = " << getFrameRate.pos.y << std::endl;

  std::count << "Area : " << getArea() << std::endl;
}
