#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

nazarov::Rectangle::Rectangle(const point_t &pos, const double &width, const double &height) :
  pos_(pos),
  width_(width),
  height_(height)
{
  if (width_ <= 0 || height_ <= 0)
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
  return { pos_, width_, height_ };
}

nazarov::point_t nazarov::Rectangle::getPos() const
{
  return pos_;
}

double nazarov::Rectangle::getWidth() const
{
  return width_;
}

double nazarov::Rectangle::getHeight() const
{
  return height_;
}

void nazarov::Rectangle::printFeatures() const
{
  rectangle_t framingRectangle = getFrameRect();
  std::cout << "Rectangle information: \n" << "Width:" << width_ << "\n"
    << "Height: " << height_ << "\n" << "Area: " << getArea() << "\n\n"
    << "Rectangle is at point: { " << "x: " << pos_.x << ", y: " << pos_.y << " }\n\n"
    << "Framing rectangle information:\n" << "Width:" << framingRectangle.width << "\n"
    << "Height: " << framingRectangle.height << "\n" << "Center : { " << "x: " << framingRectangle.pos.x
    << ", y: " << framingRectangle.pos.y << " }\n\n";
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
    throw std::invalid_argument("Enter correct 'times'");
  }
  else
  {
    width_ *= times;
    height_ *= times;
  }
}
