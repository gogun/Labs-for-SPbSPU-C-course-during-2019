#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

afanasiev::Rectangle::Rectangle(const point_t &position, double width, double height):
  position_(position),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Width and height must be positive");
  }
}

double afanasiev::Rectangle::getArea() const
{
  return width_ * height_;
}

afanasiev::rectangle_t afanasiev::Rectangle::getFrameRect() const
{
  return {position_, width_, height_};
}

void afanasiev::Rectangle::move(const point_t &newPosition)
{
  position_ = newPosition;
}

void afanasiev::Rectangle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

void afanasiev::Rectangle::scale(double zoomFactor)
{
  if (zoomFactor <= 0)
  {
    throw std::invalid_argument("Zoom factor must be positive");
  }
  else
  {
    width_ *= zoomFactor;
    height_ *= zoomFactor;
  }
}
