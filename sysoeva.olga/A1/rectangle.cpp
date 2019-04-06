#include "rectangle.hpp"

Rectangle::Rectangle(const point_t & point, const double height, const double width)
{
  assert((height_ > 0.0) && (width_ > 0.0));
  rect_.pos = point;
  rect_.height = height;
  rect_.width = width;
}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}