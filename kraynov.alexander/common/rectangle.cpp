#include "rectangle.hpp"
#include <stdexcept>

kraynov::Rectangle::Rectangle(const point_t &pos, double width, double height) :
  pos_(pos),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Attempted creation of a rectangle with width or height less than 0");
  }
}

kraynov::point_t kraynov::Rectangle::getPos() const
{
  return pos_;
}

double kraynov::Rectangle::getArea() const
{
  return width_ * height_;
}

kraynov::rectangle_t kraynov::Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

void kraynov::Rectangle::move(const point_t &pos)
{
  pos_ = pos;
}

void kraynov::Rectangle::move(double shift_x, double shift_y)
{
  pos_.x += shift_x;
  pos_.y += shift_y;
}

void kraynov::Rectangle::scale(double multiplicator)
{
  if (multiplicator <= 0)
  {
    throw std::invalid_argument("Attempted scaling by number lower than 0");
  }
  height_ *= multiplicator;
  width_ *= multiplicator;
}
