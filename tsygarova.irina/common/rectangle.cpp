#include <iostream>
#include <stdexcept>

#include "rectangle.hpp"

tsygarova::Rectangle::Rectangle(const rectangle_t &rect):
  rect_(rect)
{
  if ((rect_.height < 0.0) || (rect_.width < 0.0))
  {
    throw std::invalid_argument("Error. Invalid height or width of rectangle.\n");
  }
}

double tsygarova::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

tsygarova::rectangle_t tsygarova::Rectangle::getFrameRect() const
{
  return rect_;
}

void tsygarova::Rectangle::move(const point_t &point)
{
  rect_.pos = point;
}

void tsygarova::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void tsygarova::Rectangle::print() const
{
  std::cout << "Area of rectangle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << rect_.width << std::endl;
  std::cout << "Height of frame rectangle: " << rect_.height << std::endl;
  std::cout << "Center point of frame rectangle: (" << rect_.pos.x
            << "; " << rect_.pos.y << ")" << std::endl;
}

void tsygarova::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error.Invalid coefficient of scale.\n");
  }
  rect_.height *= coefficient;
  rect_.width *= coefficient;
}
