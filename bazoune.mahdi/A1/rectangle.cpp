#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double setWidth, double setHeight, const point_t& setCenter) :
  width_(setWidth),
  height_(setHeight),
  center_(setCenter)
{
  assert (width_ >= 0);
  assert  (height_ >= 0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{ width_, height_, center_ };
}

void Rectangle::print() const
{
  std::cout << "rectangle :"<< std:: endl;
  std::cout <<"center x = " <<center_.x <<std:: endl;
  std::cout <<"center y = " <<center_.y <<std:: endl;
  std::cout <<"width  = " << width_<<std:: endl;
  std::cout <<"height = " << height_<<std:: endl;
}

void Rectangle::move(const point_t& move)
{
  center_ = move;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
