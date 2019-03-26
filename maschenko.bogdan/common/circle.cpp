#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace maschenko
{
  Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
  {
    if (radius_ <= 0) {
      throw std::invalid_argument ("Invalid radius of circle.");
    }
  }

  double Circle::getArea() const
  {
    return M_PI * radius_ * radius_;
  }

  rectangle_t Circle::getFrameRect() const
  {
    return rectangle_t{
      center_,
      2 * radius_,
      2 * radius_
    };
  }

  void Circle::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }

  void Circle::move(const point_t &center)
  {
    center_ = center;
  }

  void Circle::scale(double coefficient)
  {
    if (coefficient > 0)
    {
      radius_ *= coefficient;
    }
    else
    {
      throw std::invalid_argument ("Invalid coefficient for circle");
    }
  }

  void Circle::writeInfo() const
  {
    rectangle_t rectangle = getFrameRect();
    std::cout << std::endl
              << "Circle with center: (" << center_.x
              << ";" << center_.y << ")" << std::endl
              << "radius = " << radius_ << std::endl
              << "Frame rectangle width = " << rectangle.width
              << ", height = " << rectangle.height << std::endl
              << "Area = " << getArea() << std::endl << std::endl;
  }

  point_t Circle::getCenter() const
  {
    return center_;
  }

  double Circle::getRadius() const
  {
    return radius_;
  }
}
