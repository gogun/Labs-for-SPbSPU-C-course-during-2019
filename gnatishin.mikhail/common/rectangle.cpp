#include "rectangle.hpp"

#include <iostream>

gnatishin::Rectangle::Rectangle(const point_t &pos, double width, double height) :
  center_(pos),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Width or height cannot be less than zero");
  }
}

double gnatishin::Rectangle::getArea() const
{
    return width_ * height_;
}

gnatishin::rectangle_t gnatishin::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

gnatishin::point_t gnatishin::Rectangle::getPosition() const
{
  return center_;
}

void gnatishin::Rectangle::move(const point_t &center)
{
  center_ = center;
}

void gnatishin::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void gnatishin::Rectangle::scale(double scaleFactor)
{
  if (scaleFactor < 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor cannot be less than zero.");
  }
  else
  {
    width_ *= scaleFactor;
    height_ *= scaleFactor;
  }
}
