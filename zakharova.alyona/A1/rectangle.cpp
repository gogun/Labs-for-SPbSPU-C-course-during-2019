#include <cassert>
#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle (const double w, const double h, point_t p):
  width_(w),
  height_(h),
  pos_(p)
{
  assert(w > 0 && h > 0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
	return {width_, height_, pos_};
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(point_t newpos)
{
  pos_ = newpos;
}

void Rectangle::getInfo() const
{
  std::cout << "Rectangle with width: " << width_ << ", height: " << height_
            << ", centre at point: (" <<pos_.x << ";" << pos_.y << ")" << std::endl;
	std::cout << "Rectangle area: " << getArea() << std::endl;
  std::cout << "Frame width: " << getFrameRect().width
            << ", height: " << getFrameRect().height
            << ", centre: (" << getFrameRect().pos.x << ";"
            << getFrameRect().pos.y << ")" << std::endl;
  std::cout << "* * *" << std::endl;
}


