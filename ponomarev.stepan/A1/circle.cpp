#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle(const point_t pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius <= 0) {
    std::cerr << "Invalid radius" << std::endl;
  }
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
  std::cout << "--------------------------" << std::endl;
  std::cout << "Centre:\n" << "x = " << pos_.x << " " << "y = " << pos_.y << std::endl;
  std::cout << "Radius = " << radius_ << std::endl;

  std::cout << "Out rectangle:\n" << "Width = " << getFrameRate().width << "\n" << "Height = " << getFrameRate().heigth << "\n"\
      << "Centre: " << "x = " << getFrameRate().pos.x << "\n" << "y = " << getFrameRate().pos.y << std::endl;

  std::cout << "Area : " << getArea() << std::endl;
  std::cout << "--------------------------" << std::endl;
}
