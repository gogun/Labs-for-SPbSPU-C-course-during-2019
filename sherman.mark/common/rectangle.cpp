#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

sherman::Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  center_(center)
{
  if (width_ <= 0)
  {
    throw std::invalid_argument("Width must be more than zero");
  }
  if (height_ <= 0)
  {
    throw std::invalid_argument("Height must be more than zero");
  }
}

double sherman::Rectangle::getArea() const
{
  return width_ * height_;
}

sherman::rectangle_t sherman::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void sherman::Rectangle::move(double changeX, double changeY)
{
  center_.x += changeX;
  center_.y += changeY;
}

void sherman::Rectangle::move(const point_t & newCenter)
{
  center_ = newCenter;
}

void sherman::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient must be more than zero");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

void sherman::Rectangle::printInformation() const
{
  std::cout << "Center of the rectangle is (" << center_.x << "," << center_.y << ")\n";
  std::cout << "Rectangle\'s width is " << width_ << '\n';
  std::cout << "Rectangle\'s height is " << height_ << '\n';
  std::cout << "Area of the rectangle is " << getArea() << '\n';
  std::cout << "Parameters of the frame rectangle: " << '\n';
  std::cout << "Width: " << getFrameRect().width << '\n';
  std::cout << "Height: " << getFrameRect().height << '\n';
  std::cout << "Center: (" << getFrameRect().pos.x << "," << getFrameRect().pos.y << ")\n";
}
