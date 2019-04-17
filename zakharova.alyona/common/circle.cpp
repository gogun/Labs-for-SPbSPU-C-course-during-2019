#include "circle.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>

zakharova::Circle::Circle(double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius must be greater than zero.");
  }
}

zakharova::rectangle_t zakharova::Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, pos_ };
}

double zakharova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void zakharova::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void zakharova::Circle::move(point_t newpos)
{
  pos_ = newpos;
}

void zakharova::Circle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scaling factor must be greater than zero.");
  }
  radius_ = radius_ * factor;
}

void zakharova::Circle::getInfo() const
{
  std::cout << "Circle with radius: " << radius_
            << ", centre at point: (" << pos_.x << ";"
            << pos_.y << ")" << std::endl;
  std::cout << "Circle area: " << getArea() << std::endl;
  std::cout << "Frame width: " << getFrameRect().width
            << ", height: " << getFrameRect().height
            << ", centre: (" << getFrameRect().pos.x << ";"
            << getFrameRect().pos.y << ")" << std::endl;
}
