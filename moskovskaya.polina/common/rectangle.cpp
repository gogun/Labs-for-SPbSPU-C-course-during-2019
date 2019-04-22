#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

moskovskaya::Rectangle::Rectangle(const moskovskaya::point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if (width_ <= 0)
  {
    throw std::invalid_argument("Negative width");
  }
  if (height_ <= 0)
  {
    throw std::invalid_argument("Negative height");
  }
}

double moskovskaya::Rectangle::getArea() const
{
  return width_ * height_;
}

moskovskaya::rectangle_t moskovskaya::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void moskovskaya::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void moskovskaya::Rectangle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void moskovskaya::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Negative factor");
  }
  width_ *= factor;
  height_ *= factor;
}
