#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>

Circle::Circle(double radius, const point_t &center):
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0.0) {
    throw std::invalid_argument("The specified circle's radius is not valid.");
  }
}

void Circle::printInfo() const
{
  std::cout << "\nCircle";
  std::cout << "\nRadius: " << radius_;
  std::cout << "\nCenter: " << center_.x << "; " << center_.y;
}

double Circle::getArea() const
{
  return (std::pow(radius_, 2.0) * M_PI);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t &newPos)
{
  center_ = newPos;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
