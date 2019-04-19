#include "circle.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const double &radius, const point_t &point):
  radius_(radius),
  center_(point)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::printInfo() const
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
