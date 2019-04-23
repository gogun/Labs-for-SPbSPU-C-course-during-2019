#include "rectangle.hpp"
#include <stdexcept>

kozhin::Rectangle::Rectangle(const kozhin::point_t& center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle width must be positive.");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle height must be positive.");
  }
}

double kozhin::Rectangle::getArea() const
{
  return width_ * height_;
}

kozhin::rectangle_t kozhin::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

kozhin::point_t kozhin::Rectangle::getCenter() const
{
  return center_;
}

void kozhin::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void kozhin::Rectangle::move(const kozhin::point_t& point)
{
  center_ = point;
}

void kozhin::Rectangle::scale(double rate)
{
  if (rate <= 0.0)
  {
    throw std::invalid_argument("Scale rate must be positive.");
  }
  width_ *= rate;
  height_ *= rate;
}
