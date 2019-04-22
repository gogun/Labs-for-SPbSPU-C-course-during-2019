#include "rectangle.hpp"
#include <iostream>
#include <cassert>


Rectangle::Rectangle(const rectangle_t &rect) :
  width_(rect.width),
  height_(rect.height),
  pos_(rect.pos)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(const double &width, const double &height, const point_t &pos) :
  width_(width),
  height_(height),
  pos_(pos)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(const double &width, const double &height, const double &posx, const double &posy) :
  width_(width),
  height_(height),
  pos_({posx, posy})
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::move(const double &x, const double &y)
{
  pos_.x += x;
  pos_.y += y;
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

const double Rectangle::getWidth()
{
  return width_;
}

const double Rectangle::getHeight()
{
  return height_;
}

const point_t Rectangle::getPos()
{
  return pos_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}
