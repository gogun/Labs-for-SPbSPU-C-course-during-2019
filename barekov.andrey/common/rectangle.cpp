#include "rectangle.hpp"

#include <iostream>
#include <cassert>

barekov::Rectangle::Rectangle(const point_t& pos, double width, double height) :
  centre_(pos),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Width and height must be positive numbers");
  }
}

barekov::Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{ }

double barekov::Rectangle::getArea() const
{
  return width_ * height_;
}

barekov::rectangle_t barekov::Rectangle::getFrameRect() const
{
  return {width_, height_, centre_};
}

barekov::point_t barekov::Rectangle::getPos() const
{
  return centre_;
}

void barekov::Rectangle::showScalableParameters() const
{
  std::cout << "\nThe size of the rectangle is " << width_ << "x" << height_ << "\n";
}

void barekov::Rectangle::move(const point_t& centre)
{
  centre_ = centre;
}

void barekov::Rectangle::move(double deltaX, double deltaY)
{
  centre_.x += deltaX;
  centre_.y += deltaY;
}

void barekov::Rectangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor must be a positive number");
  }
  else
  {
    width_ *= scaleFactor;
    height_ *= scaleFactor;
  }
}
