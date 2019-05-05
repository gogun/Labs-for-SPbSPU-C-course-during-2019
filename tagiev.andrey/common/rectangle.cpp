#include "rectangle.hpp"
#include <stdexcept>

tagiev::Rectangle::Rectangle(const tagiev::point_t &center, const double &width, const double &height) :
  center_(center),
  width_(width),
  height_(height)
{
  if ((height_ <= 0.0) || (width_ <= 0.0))
  {
    throw std::invalid_argument("W or H <= 0");
  }
}

double tagiev::Rectangle::getArea() const
{
  return (width_ * height_);
}

tagiev::rectangle_t tagiev::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void tagiev::Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void tagiev::Rectangle::move(const tagiev::point_t &newPoint)
{
  center_ = newPoint;
}

void tagiev::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("K <= 0");
  }
  width_ *= k;
  height_ *= k;
}
