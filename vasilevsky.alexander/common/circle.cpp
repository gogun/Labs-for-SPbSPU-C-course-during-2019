#include "circle.hpp"

#include <iostream>
#include <cmath>
#include <stdexcept>

vasilevsky::Circle::Circle(const double &radius, const point_t &point):
  radius_(radius),
  center_(point)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("radius of circle must be a positive number");
  }
}

double vasilevsky::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

vasilevsky::rectangle_t vasilevsky::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void vasilevsky::Circle::move(const point_t &point)
{
  center_ = point;
}

void vasilevsky::Circle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void vasilevsky::Circle::printInfo() const
{
  std::cout << "--- CIRCLE --- \n";
  std::cout << "Radius is: " << radius_ <<"\n";
  std::cout << "Center point on OX: " << center_.x << "\n";
  std::cout << "Center point on OY: " << center_.y << "\n";
  std::cout << "Area of circle is: " << getArea() << "\n";
  std::cout << "--- FRAME --- \n";
  std::cout << "Width is: " << getFrameRect().width << "\n";
  std::cout << "Height is: " << getFrameRect().height << "\n";
  std::cout << "Center point on OX: " << getFrameRect().pos.x << "\n";
  std::cout << "Center point on OY: " << getFrameRect().pos.y << "\n\n";
}

void vasilevsky::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient of scale must be a positive number");
  }
  else
  {
    radius_ *= coefficient;
  }
}
