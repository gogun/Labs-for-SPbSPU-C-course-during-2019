#include "rectangle.hpp"

#include <stdexcept>
#include <iostream>

pylaev::Rectangle::Rectangle(const point_t & center, const double width, const double height):
  center_(center),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) && (height_ <= 0.0)) {
    throw std::invalid_argument("Length of rectangle's sides must be positive");
  }
}

pylaev::Rectangle::Rectangle(const point_t & center, const double width):
  Rectangle(center, width, width)
{}

double pylaev::Rectangle::getWidth() const
{
  return width_;
}

double pylaev::Rectangle::getHeight() const
{
  return height_;
}

double pylaev::Rectangle::getArea() const
{
  return width_ * height_;
}

pylaev::rectangle_t pylaev::Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}

void pylaev::Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void pylaev::Rectangle::move(const point_t &pos)
{
  center_ = pos;
}

void pylaev::Rectangle::scale(const double kScaling)
{
  if (kScaling <= 0.0) {
    throw std::invalid_argument("Coefficient of scaling must be positive");
  }
  width_ *= kScaling;
  height_ *= kScaling;
}

void pylaev::Rectangle::printSpec() const
{
  std::cout << "Area of our rectangle is " << getArea() << " square units\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "Center of the frame rectangle with width = " << frameRectangle.width
      << " and height = " << frameRectangle.height
      << " is located in point (" << frameRectangle.pos.x << "; " << frameRectangle.pos.y << ")\n";
}
