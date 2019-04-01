#include "rectangle.hpp"
#include <cassert>
#include "base-types.hpp"

Rectangle::Rectangle(const point_t & center,const double &width,const double &height) :
  center_(center),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_,height_,center_};
}

void Rectangle::move(const point_t & position)
{
  center_ = position;
}

void Rectangle::move(const double &shift_x,const double &shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}
