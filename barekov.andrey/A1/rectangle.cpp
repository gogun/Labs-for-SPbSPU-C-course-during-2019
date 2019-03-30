#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(const point_t& pos, double width, double height) :
  centre_(pos),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{ }

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, centre_};
}

point_t Rectangle::getPos() const
{
  return centre_;
}

void Rectangle::move(const point_t& centre)
{
  centre_ = centre;
}

void Rectangle::move(double mx, double my)
{
  centre_.x += mx;
  centre_.y += my;
}
