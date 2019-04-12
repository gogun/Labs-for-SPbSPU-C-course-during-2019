#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

lutsenko::Rectangle::Rectangle(const rectangle_t & rect) :
  rect_(rect)
{
  if (rect.width <= 0)
  {
    throw std::invalid_argument("rectangle width should be greater than zero");
  };
  if (rect.height <= 0)
  {
    throw std::invalid_argument("rectangle height should be greater than zero");
  };
}

double lutsenko::Rectangle::getArea() const
{
  return (rect_.height * rect_.width);
}

lutsenko::rectangle_t lutsenko::Rectangle::getFrameRect() const
{
  return rect_;
}

void lutsenko::Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void lutsenko::Rectangle::move(double x, double y)
{
  rect_.pos.x += x;
  rect_.pos.y += y;
}

void lutsenko::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("coefficient should be greater than	zero");
  };
  rect_.height *= coefficient;
  rect_.width *= coefficient;
}
