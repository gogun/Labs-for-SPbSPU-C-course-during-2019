#include "circle.hpp"
#include <iostream>
#include <math.h>
#include <stdexcept>

bogdanov::Circle::Circle(const point_t &center, double radius):
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0) {
    throw std::invalid_argument("The radius values must be positive");
  }
}

double bogdanov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void bogdanov::Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void bogdanov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

bogdanov::rectangle_t bogdanov::Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void bogdanov::Circle::writeInfo() const
{
  rectangle_t rectangleExp = getFrameRect();
  std::cout << "Information about the Circle: \n";
  std::cout << "Radius: " << radius_ << "\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ") \n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle: width = " << rectangleExp.width << ", height = " << rectangleExp.height << "\n"
      << std::endl;
}

void bogdanov::Circle::scale(double scalingFactor)
{
  if (scalingFactor <= 0) {
    throw std::invalid_argument("Scaling factor must be positive");
  } else {
    radius_ *= scalingFactor ;
  }
}
