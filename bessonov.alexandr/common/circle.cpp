#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

  bessonov::Circle::Circle(const bessonov::point_t &newCenter, double radius) :
    center_(newCenter),
    radius_(radius)
  {
    if (radius <= 0)
    {
      throw std::invalid_argument("Problematic radius");
    }
  }

  void bessonov::Circle::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }

  void bessonov::Circle::move(const point_t &newCenter)
  {
    center_ = newCenter;
  }

  double bessonov::Circle::getArea() const
  {
    return M_PI * radius_ * radius_;
  }

  bessonov::rectangle_t bessonov::Circle::getFrameRect() const
  {
    return { 2 * radius_, 2 * radius_, center_ };
  }

  void bessonov::Circle::scale(double factor)
  {
    if (factor <= 0)
    {
      throw std::invalid_argument("Problematic factor");
    }
    radius_ *= factor;
}
