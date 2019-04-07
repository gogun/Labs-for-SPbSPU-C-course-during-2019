//
// Created by Артур on 18.03.2019.
//

#include "rectangle.hpp"

#include <cassert>

nurtdinov::Rectangle::Rectangle(const nurtdinov::point_t &point, double width, double height) :
  width_(width),
  height_(height),
  position_(point)
{
  assert(width_ > 0.0 && height_ > 0.0);
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

nurtdinov::point_t nurtdinov::Rectangle::getCenter() const
{
  return position_;
}

void nurtdinov::Rectangle::scale(double rate)
{
  assert(rate > 0.0);
  width_ *= rate;
  height_ *= rate;
}
