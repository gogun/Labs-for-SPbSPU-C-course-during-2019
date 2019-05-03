#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

sherman::Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius must be more than zero");
  }
}

double sherman::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

sherman::rectangle_t sherman::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void sherman::Circle::move(double changeX, double changeY)
{
  center_.x += changeX;
  center_.y += changeY;
}

void sherman::Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void sherman::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient must be more than zero");
  }
  radius_ *= coefficient;
}

void sherman::Circle::printInformation() const
{
  std::cout << "Center of the circle is (" << center_.x << "," << center_.y << ")\n";
  std::cout << "Circle radius is " << radius_<< '\n';
  std::cout << "Area of the circle is " << getArea() << '\n';
  std::cout << "Parameters of the frame rectangle: " << '\n';
  std::cout << "Width: " << getFrameRect().width << '\n';
  std::cout << "Height: " << getFrameRect().height << '\n';
  std::cout << "Center: (" << getFrameRect().pos.x << "," << getFrameRect().pos.y << ")\n";
}
