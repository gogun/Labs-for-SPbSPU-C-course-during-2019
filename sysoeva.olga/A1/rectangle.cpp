#include "rectangle.hpp"

Rectangle::Rectangle(const point_t & point, const double height_, const double width_)
{
  assert((height_ > 0.0) && (width_ > 0.0));
  rect.pos = point;
  rect.height = height_;
  rect.width = width_;
}

double Rectangle::getArea() const
{
  return rect.width * rect.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect;
}

void Rectangle::move(const point_t & point)
{
  rect.pos = point;
}

void Rectangle::move(const double dx, const double dy)
{
  rect.pos.x += dx;
  rect.pos.y += dy;
}
