#include "rectangle.hpp"
#include <stdexcept>

rakhmatullin::Rectangle::Rectangle(const rakhmatullin::point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if ((width_ < 0.0) || (height_ < 0.0)) {
    throw std::invalid_argument("Rectangle width and height should be positive");
  }
}

double rakhmatullin::Rectangle::getArea() const
{
  return (width_ * height_);
}

rakhmatullin::rectangle_t rakhmatullin::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void rakhmatullin::Rectangle::move(const rakhmatullin::point_t & position)
{
  center_ = position;
}

void rakhmatullin::Rectangle::move(double shift_x, double shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void rakhmatullin::Rectangle::scale(double factor)
{
  if (factor < 0.0) {
    throw std::invalid_argument("Factor of scale should be positive");
  }
  width_ *= factor;
  height_ *= factor;
}
