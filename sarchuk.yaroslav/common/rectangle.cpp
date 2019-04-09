#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>

sarchuk::Rectangle::Rectangle(point_t position, double width, double height) :
  pos_(position),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Width and height must be more than 0");
  }
}

sarchuk::Rectangle::Rectangle(rectangle_t info) :
  pos_(info.pos),
  width_(info.width),
  height_(info.height)
{
  if ((info.width <= 0) || (info.height <= 0))
  {
    throw std::invalid_argument("Width and height must be more than 0");
  }
}

double sarchuk::Rectangle::getArea() const
{
  return width_ * height_;
}

void sarchuk::Rectangle::writeInfo() const
{
  std::cout << "Rectangle info:\n"
            << "Width - " << width_ << "\n"
            << "Height - " << height_ << "\n"
            << "Center position - x = " << pos_.x << ", y = " << pos_.y << "\n"
            << "Area - " << getArea() << "\n\n";
}

sarchuk::rectangle_t sarchuk::Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

void sarchuk::Rectangle::move(point_t pos)
{
  pos_ = pos;
}

void sarchuk::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void sarchuk::Rectangle::scale(double mult)
{
  if (mult <= 0)
  {
    throw std::invalid_argument("Multiplier must be more than 0");
  }
  width_ *= mult;
  height_ *= mult;
}
