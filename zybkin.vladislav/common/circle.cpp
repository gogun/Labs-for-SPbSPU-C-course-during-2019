#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

zybkin::Circle::Circle(const zybkin::point_t &position, const double &radius) :
  radius_(radius),
  center_(position)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius has to be positive");
  }
}

double zybkin::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

zybkin::rectangle_t zybkin::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void zybkin::Circle::printInfo() const
{
  std::cout << "Information about circle:\n";
  std::cout << "Radius: " << radius_ << ",\n";
  std::cout << "Area of circle: " << getArea() << ",\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ").\n";
  std::cout << "Frame rectangle:" << "\n";
  zybkin::rectangle_t frameRectangle = getFrameRect();
  std::cout << "width: " << frameRectangle.width << "\n";
  std::cout << "height: " << frameRectangle.height << "\n";
  std::cout << "Center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ").\n\n";
}

void zybkin::Circle::move(const zybkin::point_t &position)
{
  center_ = position;
}

void zybkin::Circle::move(const double &shift_x, const double &shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void zybkin::Circle::scale(const double &coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("Coef has to be positive");
  }
  radius_ *= coef;
}
