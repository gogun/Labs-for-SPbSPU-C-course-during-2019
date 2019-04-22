#include "rectangle.hpp"
#include <stdexcept>

besedin::Rectangle::Rectangle(const double width, const double height, const point_t &center) :
  width_(width),
  height_(height),
  center_(center)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Wrong rectangle width");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Wrong rectangle height");
  }
}

double besedin::Rectangle::getArea() const noexcept
{
  return width_ * height_;
}

besedin::rectangle_t besedin::Rectangle::getFrameRect() const noexcept
{
  return {width_, height_, center_};
}

void besedin::Rectangle::move(const double dx, const double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void besedin::Rectangle::move(const point_t &newPos) noexcept
{
  center_ = newPos;
}

void besedin::Rectangle::scale(const double scale)
{
  if (scale <= 0.0)
  {
    throw std::invalid_argument("Wrong scaling factor");
  }
  width_ *= scale;
  height_ *= scale;
}
