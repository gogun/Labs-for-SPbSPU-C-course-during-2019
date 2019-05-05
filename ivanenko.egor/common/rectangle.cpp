#include "rectangle.hpp"
#include "base-types.hpp"
#include <cassert>
#include <stdexcept>

ivanenko::Rectangle::Rectangle(double width, double height, const point_t &pos) :
  width_(width),
  height_(height),
  pos_(pos)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Invalid width");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Invalid height");
  }
}
double ivanenko::Rectangle::getArea() const
{
  return width_ * height_;
}

ivanenko::rectangle_t ivanenko::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void ivanenko::Rectangle::move(const point_t &pos)
{
  pos_ = pos;
}

void ivanenko::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void ivanenko::Rectangle::scale(const double scale)
{
  if (scale <= 0.0)
  {
    throw std::invalid_argument("Invalid scale");
  }
  width_ *= scale;
  height_ *= scale;
}

