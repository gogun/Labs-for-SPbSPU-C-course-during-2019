#include "rectangle.hpp"

#include <stdexcept>

using namespace alexandrov;

alexandrov::Rectangle::Rectangle(const rectangle_t & rect):
  rect_(rect)
{
  if (rect_.width <= 0.0)
  {
    throw std::invalid_argument("The width of the rectangle must be greater than zero.");
  }
  if (rect_.height <= 0.0)
  {
    throw std::invalid_argument("The height of the rectangle must be greater than zero.");
  }
}

void alexandrov::Rectangle::move(const point_t & newPoint)
{
  rect_.pos = newPoint;
}

void alexandrov::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void alexandrov::Rectangle::scale(const double factor)
{
  if (factor > 0.0)
  {
    rect_.width *= factor;
    rect_.height *= factor;
  }
  else
  {
    throw std::invalid_argument("Method scale must have a factor greater than zero.");
  }
}

double alexandrov::Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

rectangle_t alexandrov::Rectangle::getFrameRect() const
{
  return rect_;
}
