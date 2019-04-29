#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

kurbanova::Rectangle::Rectangle(const point_t &center, double width1, double height1):
  pos_(center),
  width_(width1),
  height_(height1)
{
  if ((width1 <= 0) || (height1 <= 0))
  {
    throw std::invalid_argument("Invalid height or width");
  }
}

double kurbanova::Rectangle::getArea() const
{
  return(width_ * height_);
}

kurbanova::rectangle_t kurbanova::Rectangle::getFrameRect() const
{
  return{pos_, width_, height_};
}

void kurbanova::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void kurbanova::Rectangle::move(const point_t &pos1)
{
  pos_ = pos1;
}

void kurbanova::Rectangle::scale(double coefficient)
{
  if (coefficient > 0)
  {
    width_ *= coefficient;
    height_ *= coefficient;
  }
  else
  {
    throw std::invalid_argument("Invalid rectangle's coefficient");
  }
}

void kurbanova::Rectangle::printInfo() const
{
  std::cout << "Area = " << getArea() << "\n"
            << "Width = " << width_ << ", height = " << height_ << "\n"
            << "Position (" << pos_.x << ", " << pos_.y << ")\n";
}
