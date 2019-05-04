#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>

zakharova::Rectangle::Rectangle(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if ((width <= 0) || (height <=0))
  {
    throw std::invalid_argument("Width and height must be greater than zero.");
  }
}

double zakharova::Rectangle::getArea() const
{
  return width_ * height_;
}

zakharova::rectangle_t zakharova::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void zakharova::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void zakharova::Rectangle::move(point_t newpos)
{
  pos_ = newpos;
}

void zakharova::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scaling factor must be greater than zero.");
  }
  width_ = width_ * factor;
  height_ = height_ * factor;
}

void zakharova::Rectangle::getInfo() const
{
  std::cout << "Rectangle with width: " << width_ << ", height: " << height_
            << ", centre at point: (" <<pos_.x << ";" << pos_.y << ")" << std::endl;
  std::cout << "Rectangle area: " << getArea() << std::endl;
  std::cout << "Frame width: " << getFrameRect().width
            << ", height: " << getFrameRect().height
            << ", centre: (" << getFrameRect().pos.x << ";"
            << getFrameRect().pos.y << ")" << std::endl;
}
