#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

fedorov::Rectangle::Rectangle(const point_t &position, const double width, const double height):
  Shape(position),
  width_(width),
  height_(height)
{
  if ((width_ <= 0) || (height_ <= 0))
  {
    throw std::invalid_argument("Incorrect width or height");
  }
}

fedorov::rectangle_t fedorov::Rectangle::getFrameRect() const
{
  return { position_, width_, height_ };
}

double fedorov::Rectangle::getArea() const
{
  return width_ * height_;
}

double fedorov::Rectangle::getWidth() const
{
  return width_;
}

double fedorov::Rectangle::getHeight() const
{
  return height_;
}

void fedorov::Rectangle::printInfo() const
{
  Shape::printInfo();
  std::cout << "\t width: " << width_ << " \t height: " << height_ << std::endl
      << "\t area: " << getArea() << std::endl
      << "\t frame:" << std::endl
      << "\t\tcenter: (" << getFrameRect().pos.x << ";" << getFrameRect().pos.y << ")" << std::endl
      << "\t\twidth: " << getFrameRect().width << "\theight: " << getFrameRect().height << std::endl
      << std::endl;
}

void fedorov::Rectangle::scale(double scale)
{
  if (scale <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
	width_ *= scale;
	height_ *= scale;
}
