#include "rectangle.hpp"
#include <iostream>
#include <cassert>

malinovskaya::Rectangle::Rectangle(const rectangle_t &rectangle) :
  rectangle_(rectangle)
{
  if ((rectangle_.width <= 0.0) || (rectangle_.height <= 0.0))
  {
    throw std::invalid_argument("Width and height should be positive");
  }
}

double malinovskaya::Rectangle::getArea() const
{
  return (rectangle_.width * rectangle_.height);
}

malinovskaya::rectangle_t malinovskaya::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void malinovskaya::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void malinovskaya::Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}

void malinovskaya::Rectangle::print() const
{
  std::cout << "Center: (" << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << std::endl;
}

void malinovskaya::Rectangle::scale(const double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("Scale coefficient should be positive");
  }
  else
  {
    rectangle_.width *= coeff;
    rectangle_.height *= coeff;
  }
}
