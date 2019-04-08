#include "rectangle.hpp"
#include <iostream>
#include <cassert>


Rectangle::Rectangle(const point_t &p, const double &w, const double &h) :
  width_(w),
  height_(h),
  center(p)
{
  assert(height_ > 0 && width_ > 0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, center_ };
}

void Rectangle::setWidth(const double &w)
{
  assert(w > 0);
  width_ = w;
}

void Rectangle::setHeight(const double &h)
{
  assert(h > 0);
  height_ = h;
}

void Rectangle::move(const point_t &p)
{
  center_.x = p.x;
  center_.y = p.y;
}


void Rectangle::move(const double &x, const double &y)
{
  center_.x += x;
  center_.y += y;
}

void Rectangle::printInfo() const
{
  std::cout << "\n**********************\n";
  std::cout << "rectangle info:\ncenter=(" << center_.x << ";" << center_.y << ")\nwidth=" << width_
    << "\nheight=" << height_ << "\nArea=" << getArea();
  std::cout << "\n**********************";
}

void Rectangle::getCenterInfo() const
{
  std::cout << "Center X: " << center.x << "Center Y: " << center.y;
}
