#include <cassert>
#include <cmath>
#include <stdexcept>
#include "rectangle.hpp"

pavlova::Rectangle::Rectangle(double height, double  width, const point_t &center):
  height_(height),
  width_(width),
  center_(center)
{
  if ((height <= 0) || (width <= 0))
  {
    throw std::invalid_argument("Height or width is negative or zero");
  }
}

double pavlova::Rectangle::getArea() const
{
  return width_ * height_;
}

pavlova::rectangle_t pavlova::Rectangle::getFrameRect() const
{
  return {height_, width_, center_};
}

void pavlova::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void pavlova::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void pavlova::Rectangle::scale(double coeff)
{
  if (coeff <= 0)
  {
    throw std::invalid_argument("Coeff is negative or zero");
  }
  else
  {
    height_ *= coeff;
    width_ *= coeff;
  }
}
