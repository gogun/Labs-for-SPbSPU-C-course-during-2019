#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t & Centre, double width, double height):
  Shape(Centre),
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
  rectangle_t frameRect;
  frameRect.height = height_;
  frameRect.width = width_;
  frameRect.pos = centre_;
  return frameRect;
}

void Rectangle::move(const point_t & newCentre)
{
  centre_ = newCentre;
}

void Rectangle::move(double newX, double newY)
{
  centre_.x = newX;
  centre_.y = newY;
}

void Rectangle::setWidth(double newWidth)
{
  width_ = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
  height_ = newHeight;
}
