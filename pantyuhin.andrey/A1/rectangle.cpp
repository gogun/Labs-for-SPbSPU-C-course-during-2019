#include "rectangle.hpp"
#include <iostream>
#include <cassert> 

Rectangle::Rectangle(point_t centre, double widh, double height):

  centre_(centre), 
  widh_(widh),
  height_(height)
{
  assert(widh_ > 0 && "widh of rectangle can't be <= 0");
  assert(height_ > 0 && "height of rectangle can't be <= 0");
}

Rectangle::Rectangle(double x, double y, double widh, double height) :
  widh_(widh),
  height_(height)
{
  assert(widh_ > 0 && "widh of rectangle can't be <= 0");
  assert(height_ > 0 && "height of rectangle can't be <= 0");
  centre_.x = x;
  centre_.y = y;
}

point_t Rectangle::getPos() const
{
  return centre_;
}

double Rectangle::getWidh() const
{
  return widh_;
}

double Rectangle::getHeight() const
{
  return height_;
}

double Rectangle::getArea() const 
{
  return (widh_*height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {centre_, widh_, height_};
}

void Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void Rectangle::move(point_t centre)
{
  centre_ = centre;
}
