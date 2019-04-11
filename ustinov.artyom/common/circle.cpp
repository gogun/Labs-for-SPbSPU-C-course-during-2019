#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

ustinov::Circle::Circle(const point_t &goal, double rad):
  center_(goal),
  radius_(rad)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Invalid radius of circle.");
  }
}

double ustinov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

ustinov::rectangle_t ustinov::Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void ustinov::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient for circle");
  }
  else
  {
    radius_*=coefficient;
  }
};

void ustinov::Circle::move(const point_t &goal)
{
  center_ = goal;
}

void ustinov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void ustinov::Circle::show() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << std::endl
            << "Coordinates of centre circle (" << center_.x
            << ";" << center_.y << ")" << std::endl
            << "radius = " << radius_ << std::endl
            << "Frame rectangle width = " << rectangle.width
            << ", height = " << rectangle.height << std::endl
            << "Area = " << getArea() << std::endl << std::endl;
}
