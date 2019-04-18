#include "rectangle.hpp"
#include <stdexcept>

karpenko::Rectangle::Rectangle(const rectangle_t & rect) :
  rect_(rect)
{
  if ((rect.width <= 0.0) || (rect.height <= 0.0))
  {
    throw std::invalid_argument("Width and height must be positive numbers");
  }
}

double karpenko::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

karpenko::rectangle_t karpenko::Rectangle::getFrameRect() const
{
  return rect_;
}

void karpenko::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void karpenko::Rectangle::move(const point_t & newPos)
{
  rect_.pos = newPos;
}

void karpenko::Rectangle::scale(double scaleRatio)
{
  if (scaleRatio < 0)
  {
    throw std::invalid_argument("scaleRatio should be positive value!");
  }
  rect_.height *= scaleRatio;
  rect_.width *= scaleRatio;
}
