#include "circle.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>

nazarov::Circle::Circle(const point_t &pos, double radius) :
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius must be more than 0");
  }
}

double nazarov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

nazarov::rectangle_t nazarov::Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void nazarov::Circle::printFeatures() const
{
  rectangle_t framingRectangle = getFrameRect();
  std::cout << "\n Circle frame width is " << framingRectangle.width;
  std::cout << "\n Circle frame height is " << framingRectangle.height;
  std::cout << "\n Circle position is ( " << "x: " << pos_.x << ", y: " << pos_.y << " )";
  std::cout << "\n Circle area is " << getArea() << "\n\n";
}

void nazarov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void nazarov::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void nazarov::Circle::scale(double times)
{
  if (times <= 0)
  {
    throw std::invalid_argument("Enter times correctly");
  }
  else
  {
    radius_ *= times;
  }
}
