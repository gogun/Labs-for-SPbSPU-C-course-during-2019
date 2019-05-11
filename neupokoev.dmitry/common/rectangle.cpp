#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

neupokoev::Rectangle::Rectangle(const rectangle_t &parameters) :
  rect_(parameters)
{
  if ((rect_.width <= 0.0) || (rect_.height <= 0.0))
  {
    throw std::invalid_argument("Width and height must be positive numbers");
  }
}

double neupokoev::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

neupokoev::rectangle_t neupokoev::Rectangle::getFrameRect() const
{
  return rect_;
}

void neupokoev::Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}

void neupokoev::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void neupokoev::Rectangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor must be a positive number");
  }
  else
  {
    rect_.width *= scaleFactor;
    rect_.height *= scaleFactor;
  }
}


void neupokoev::Rectangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle centre is (" << rect_.pos.x << ","
      << rect_.pos.y << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
