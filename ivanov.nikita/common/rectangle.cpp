#include "rectangle.hpp"
#include <iostream>

ivanov::Rectangle::Rectangle(const rectangle_t &rect):
  rect_(rect)
{
  if ((rect_.height <= 0) || (rect_.width <= 0))
  {
    throw std::invalid_argument("Incorrect height or width of rectangle");
  }
}

double ivanov::Rectangle::getArea() const
{
  return (rect_.height * rect_.width);
}

ivanov::rectangle_t ivanov::Rectangle::getFrameRect() const
{
  return rect_;
}

void ivanov::Rectangle::move(const point_t &point)
{
  rect_.pos = point;
}

void ivanov::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void ivanov::Rectangle::draw() const
{
  std::cout << "Width of frame rectangle: " << rect_.width << "\n";
  std::cout << "Height of frame rectangle: " << rect_.height << "\n";
  std::cout << "Area of rectangle: " << getArea() << "\n";
  std::cout << "Center of frame rectangle: (" << rect_.pos.x
            << "; " << rect_.pos.y << ")" << "\n";
}

void ivanov::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient of scale.");
  }
  else
  {
    rect_.height *= coefficient;
    rect_.width *= coefficient;
  }
}
