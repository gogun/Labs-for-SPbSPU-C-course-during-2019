#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t & centre, double width, double height):
  Shape(centre),
  width_(width),
  height_(height)
{
  assert((width>0) && (height>0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frameRect{ width_,
    height_,
    centre_ };
  return frameRect;
}

void Rectangle::move(const point_t & newCentre)
{
  centre_ = newCentre;
}

void Rectangle::move(double dX, double dY)
{
  centre_.x += dX;
  centre_.y += dY;
}

void Rectangle::setWidth(double newWidth)
{
  width_ = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
  height_ = newHeight;
}
