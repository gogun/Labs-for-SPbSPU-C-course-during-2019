#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

zybkin::Rectangle::Rectangle(const zybkin::point_t &position, const double &width, const double &height) :
  height_(height),
  width_(width),
  center_(position)
{
  if (height_ <= 0)
  {
    throw std::invalid_argument("Height has to be positive");
  }
  if (width_ <= 0)
  {
    throw std::invalid_argument("Width has to be positive");
  }
}

double zybkin::Rectangle::getArea() const
{
  return (width_ * height_);
}

zybkin::rectangle_t zybkin::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void zybkin::Rectangle::printInfo() const
{
  std::cout << "Information about rectangle:\n";
  std::cout << "Width: " << width_ << ",\n";
  std::cout << "Height: " << height_ << ",\n";
  std::cout << "Area of rectangle: " << getArea() << ",\n";
  std::cout << "Center: (" << center_.x << "," << center_.y << ").\n";
  zybkin::rectangle_t frameRectangle = getFrameRect();
  std::cout << "width: " << frameRectangle.width << "\n";
  std::cout << "height: " << frameRectangle.height << "\n";
  std::cout << "Center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ").\n\n";
}

void zybkin::Rectangle::move(const zybkin::point_t &position)
{
  center_ = position;
}

void zybkin::Rectangle::move(const double &shift_x, const double &shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void zybkin::Rectangle::scale(const double &coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("Coef has to be positive");
  }
  width_ *= coef;
  height_ *= coef;
}
