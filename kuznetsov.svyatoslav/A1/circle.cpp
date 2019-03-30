#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &position, const double &radius) :
  radius_(radius),
  center_(position)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t &position)
{
  center_ = position;
}

void Circle::move (const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::printInfo() const
{
  std::cout << "Information about circle: \n";
  std::cout << "Radius: " << radius_ << "\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ")\n";
  std::cout << "Area of circle: " << getArea() << "\n";
  std::cout << "Frame rectangle: \n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "width: " << frameRectangle.width << "\n";
  std::cout << "height: " << frameRectangle.height << "\n";
  std::cout << "center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ")\n\n";
}
