#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>

nazarov::Rectangle::Rectangle(const point_t &pos, double width, double height) :
  pos_(pos),
  width_(width),
  height_(height)
{
  if ((width_ <= 0) || (height_ <= 0))
  {
    throw std::invalid_argument("Width and height must be more than 0");
  }
}

double nazarov::Rectangle::getArea() const
{
  return width_ * height_;
}

nazarov::rectangle_t nazarov::Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

void nazarov::Rectangle::printFeatures() const
{
  rectangle_t framingRectangle = getFrameRect();
  std::cout << "\n Rectangle frame width is " << framingRectangle.width;
  std::cout << "\n Rectangle frame height is " << framingRectangle.height;
  std::cout << "\n Rectangle position is ( " << "x: " << pos_.x << ", y: " << pos_.y << " )";
  std::cout << "\n Rectangle area is " << getArea() << "\n\n";
}

void nazarov::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void nazarov::Rectangle::move(const point_t &pos)
{
  pos_ = pos;
}

void nazarov::Rectangle::scale(double times)
{
  if (times <= 0)
  {
    throw std::invalid_argument("times should be positive");
  }
  else
  {
    width_ *= times;
    height_ *= times;
  }
}
