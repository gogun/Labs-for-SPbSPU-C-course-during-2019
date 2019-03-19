#include "Rectangle.hpp"

const float Rectangle::getArea()
{
  return width_ * height_;
}

const rectangle_t Rectangle::getFrameRect()
{
  rectangle_t frameRect;
  frameRect.height = height_;
  frameRect.width = width_;
  frameRect.pos = centre_;
  return frameRect;
}

void Rectangle::move(point_t & newCentre)
{
  centre_ = newCentre;
}

void Rectangle::move(float newX, float newY)
{
  centre_.x = newX;
  centre_.y = newY;
}

void Rectangle::setWidth(float newWidth)
{
  width_ = newWidth;
}

void Rectangle::setHeight(float newHeight)
{
  height_ = newHeight;
}