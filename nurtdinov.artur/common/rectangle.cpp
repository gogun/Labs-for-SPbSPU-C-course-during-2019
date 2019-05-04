#include "rectangle.hpp"

#include <stdexcept>

nurtdinov::Rectangle::Rectangle(const point_t &point, double width, double height) :
  position_(point),
  width_(width),
  height_(height)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Width must be positive.");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Height must be positive.");
  }
}

double nurtdinov::Rectangle::getArea() const
{
  return width_ * height_;
}

nurtdinov::rectangle_t nurtdinov::Rectangle::getFrameRect() const
{
  return {width_, height_, position_};
}

void nurtdinov::Rectangle::move(const nurtdinov::point_t &point)
{
  position_ = point;
}

void nurtdinov::Rectangle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

void nurtdinov::Rectangle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Scale ratio must be positive");
  }
  width_ *= ratio;
  height_ *= ratio;
}
