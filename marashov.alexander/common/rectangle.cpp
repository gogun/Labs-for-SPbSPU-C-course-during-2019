#include "rectangle.hpp"
#include <iostream>
#include <cassert>

marashov::Rectangle::Rectangle(const point_t & pos, double width, double height) :
  center_(pos),
  width_(width),
  height_(height)
{
  if (width <= 0 || height <= 0)
  {
    throw std::invalid_argument("Width and height of the rectangle must be positive");
  }
}

marashov::Rectangle::Rectangle(double posX, double posY, double width, double height) :
  Rectangle({posX, posY}, width, height)
{ }

double marashov::Rectangle::getArea() const
{
  return width_ * height_;
}

marashov::rectangle_t marashov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void marashov::Rectangle::move(const point_t & pos)
{
  center_ = pos;
}

void marashov::Rectangle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void marashov::Rectangle::scale(double scaleAmount)
{
  assert(scaleAmount > 0);
  width_ *= scaleAmount;
  height_ *= scaleAmount;
}

void marashov::Rectangle:: writeInfo() const { // проверить отступы
  std::cout << "Rectangle. Center at (" << center_.x << "; " << center_.y << ")"
            << std::endl << "Width = " << width_
            << std::endl << "Height = " << height_
            << std::endl << "Area = " << getArea()
            << std::endl << std::endl;
}

marashov::point_t marashov::Rectangle::getCenter() const
{
  return center_;
}

double marashov::Rectangle::getWidth() const
{
  return width_;
}

double marashov::Rectangle::getHeight() const
{
  return height_;
}
