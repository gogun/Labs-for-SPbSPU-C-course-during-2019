#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

vlasenko::Rectangle::Rectangle(const vlasenko::point_t &position, double width, double height) :
  height_(height),
  width_(width),
  center_(position)
{

    if (height_ <= 0.0)
    {
      throw std::invalid_argument("Need a positive value of height");
    }
    if (width_ <= 0.0)
    {
      throw std::invalid_argument("Need a positive value of Width");
    }
}

double vlasenko::Rectangle::getArea() const
{
  return (width_ * height_);
}

vlasenko::rectangle_t vlasenko::Rectangle::getFrameRect() const
{
  return { width_, height_, center_ };
}

void vlasenko::Rectangle::printInfo() const
{
  std::cout << "\t Information about rectangle:\n";
  std::cout << "\t Width: " << width_ << " \n";
  std::cout << "\t Height: " << height_ << " \n";
  std::cout << "\t Area of rectangle: " << getArea() << " \n";
  std::cout << "\t Center: (" << center_.x << "," << center_.y << ").\n";
  vlasenko::rectangle_t frameRectangle = getFrameRect();
  std::cout << "\t Polymorphism: \n";
  std::cout << "\t Width: " << frameRectangle.width << "\n";
  std::cout << "\t Height: " << frameRectangle.height << "\n";
  std::cout << "\t Center: (" << frameRectangle.pos.x << "," << frameRectangle.pos.y << ").\n\n";
}

void vlasenko::Rectangle::move(const point_t & position)
{
  center_ = position;
}

void vlasenko::Rectangle::move(const double & shift_x, const double & shift_y)
{
  center_.x += shift_x;
  center_.y += shift_y;
}

void vlasenko::Rectangle::scale(double value)
{
  if (value <= 0)
  {
    throw std::invalid_argument("Need a positive value");
  }
  width_ *= value;
  height_ *= value;
}
