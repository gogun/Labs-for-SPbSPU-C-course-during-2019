#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

gusarov::Rectangle::Rectangle(const gusarov::point_t &center, const double width, const double height, const double angle):
  center_(center),
  width_(width),
  height_(height),
  angle_(angle)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Invalid width or height value");
  }
}

double gusarov::Rectangle::getArea() const
{
  return width_ * height_;
}

gusarov::rectangle_t gusarov::Rectangle::getFrameRect() const
{
  const double cos = std::abs(std::cos(angle_ * M_PI / 180));
  const double sin = std::abs(std::sin(angle_ * M_PI / 180));
  const double width = fabs(cos * width_) + fabs(sin * height_);
  const double height = fabs(cos * height_) + fabs(sin * width_);

  return {width, height, center_};
}

void gusarov::Rectangle::move(const double shiftX, const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}

void gusarov::Rectangle::move(const gusarov::point_t &newPoint)
{
  center_ = newPoint;
}

void gusarov::Rectangle::printInfo() const
{
  std::cout << "Width of rectangle is " << width_ << '\n';
  std::cout << "Height of rectangle is " << height_ << '\n';
  std::cout << "Center of rectangle is a point: (" << center_.x << ";" << center_.y << ")" << '\n';
  std::cout << "Angle of rotation is " << angle_ << '\n';
}

void gusarov::Rectangle::scale(const double scale)
{
  if (scale <= 0)
  {
    throw std::invalid_argument("Invalid scale value");
  }
  width_ *= scale;
  height_ *= scale;
}

double gusarov::Rectangle::getHeight() const
{
  return height_;
}

double gusarov::Rectangle::getWidth() const
{
  return width_;
}

void gusarov::Rectangle::rotate(double angle)
{
  angle_ += angle;
}
