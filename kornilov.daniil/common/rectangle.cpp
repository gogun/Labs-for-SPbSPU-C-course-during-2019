#include "rectangle.hpp"
#include <stdexcept>

kornilov::Rectangle::Rectangle(const rectangle_t &parameters):
  rectangle_(parameters)
{
  if (rectangle_.height <= 0 || rectangle_.width <= 0)
  {
    throw std::invalid_argument("Invalid height or width!");
  }
}

double kornilov::Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

kornilov::rectangle_t kornilov::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void kornilov::Rectangle::move(const double dx, const double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void kornilov::Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}

void kornilov::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient!");
  }
  rectangle_.width *= coefficient;
  rectangle_.height *= coefficient;
}
