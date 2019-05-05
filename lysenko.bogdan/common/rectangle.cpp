#include "rectangle.hpp"
#include <iostream>

lysenko::Rectangle::Rectangle(const rectangle_t & rect):
  rect_(rect)
{
  if (rect_.height <= 0.0)
  {
    throw std::invalid_argument("Error. Incorrect height of rectangle.");
  }
  if (rect_.width <= 0.0)
  {
    throw std::invalid_argument("Error. Incorrect width of rectangle.");
  }
}

double lysenko::Rectangle::getArea() const
{
  return (rect_.height * rect_.width);
}

lysenko::rectangle_t lysenko::Rectangle::getFrameRect() const
{
  return rect_;
}

void lysenko::Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void lysenko::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void lysenko::Rectangle::print() const
{
  std::cout << "Area of rectangle: " << getArea() << "\n";
  std::cout << "Width of frame rectangle: " << rect_.width << "\n";
  std::cout << "Height of frame rectangle: " << rect_.height << "\n";
  std::cout << "Center point of frame rectangle: (" << rect_.pos.x
            << "; " << rect_.pos.y << ")" << "\n";
}

void lysenko::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Error.Incorrect coefficient of scale.");
  }
  else
  {
    rect_.height *= coefficient;
    rect_.width *= coefficient;
  }
}
