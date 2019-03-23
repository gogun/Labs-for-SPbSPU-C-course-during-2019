#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &center, double width, double height)
{
  this->center_ = center;
  this->width_ = width;
  this->height_ = height;
  this->area_ = width * height;
  this->frameRect_ = {width, height, center};
}

double Rectangle::getArea() const
{
  return this->area_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return this->frameRect_;
}

void Rectangle::move(double x, double y)
{
  this->center_.x += x;
  this->center_.y += y;
  this->frameRect_.pos = this->center_;
}

void Rectangle::move(const point_t &point)
{
  this->center_ = point;
  this->frameRect_.pos = this->center_;
}
