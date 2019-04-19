#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

frolov::Rectangle::Rectangle(const point_t &center, double height, double width) :
  center_(center),
  height_(height),
  width_(width)
{
  if ((height_ <= 0) || (width_ <= 0))
  {
    throw std::invalid_argument("Invalid height or width!");
  }
}

double frolov::Rectangle::getArea() const
{
  return height_ * width_;
}

void frolov::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void frolov::Rectangle::move(const point_t &center)
{
  center_ = center;
}

frolov::rectangle_t frolov::Rectangle::getFrameRect() const
{
  return {center_, height_, width_};
}

void frolov::Rectangle::showPoint() const
{
  std::cout << "the point on the x-axis " << center_.x << "\n";
  std::cout << "the point on the y-axis " << center_.y << "\n";
}

void frolov::Rectangle::scale(double factor)
{
  if (factor < 0)
  {
    throw std::invalid_argument("Area can't be negativ");
  }
  height_ *= factor;
  width_ *= factor;
}
