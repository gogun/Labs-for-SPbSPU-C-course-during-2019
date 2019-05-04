#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>
#include "base-types.hpp"

borshchev::Rectangle::Rectangle(const point_t & pos, double width, double height) :
  center_(pos),
  width_(width),
  height_(height)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Incorrect value, WIDTH should be positive");
  }
  if (height <= 0.0)
  {
    throw std::invalid_argument("Incorrect value, HEIGHT should be positive");
  }
}

double borshchev::Rectangle::getArea() const
{
  return width_ * height_;
}

borshchev::rectangle_t borshchev::Rectangle::getFrameRect() const
{
  return { center_, width_, height_ };
}

void borshchev::Rectangle::move(const double newX, const double newY)
{
  center_.x += newX;
  center_.y += newY;
}

void borshchev::Rectangle::move(const point_t & point)
{
  center_ = point;
}

void borshchev::Rectangle::dataOutput() const
{
  std::cout << "Rectangle's CENTER: " << center_.x << " " << center_.y << '\n'
    << "Rectangle's WIDTH: " << width_ << '\n'
    << "Rectangle's HEIGHT: " << height_ << '\n';
}

void borshchev::Rectangle::scale(double scalingCoefficient)
{
  if (scalingCoefficient <= 0)
  {
    throw std::invalid_argument("Incorrect value, scaling COEFFICIENT should be positive");
  }
  width_ *= scalingCoefficient;
  height_ *= scalingCoefficient;
}
