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

Rectangle::Rectangle(double width, double height, const point_t &pos) :
  width_(width),
  height_(height),
  pos_(pos)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(double width, double height, double posx, double posy) :
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

void Rectangle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

double Rectangle::getWidth() const
{
  return width_;
}

double Rectangle::getHeight() const
{
  return height_;
}

point_t Rectangle::getPos() const
{
  return pos_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}
