#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

bogdanov::Rectangle::Rectangle(const point_t &center, double width, double height):
  rectangle_({center, width, height})
{
  if ((rectangle_.width <= 0) || (rectangle_.height <= 0)) {
    throw std::invalid_argument("The height and width values must be positive");
  }
}

void bogdanov::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void bogdanov::Rectangle::move(const point_t &center)
{
  rectangle_.pos = center;
}

double bogdanov::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

bogdanov::rectangle_t bogdanov::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void bogdanov::Rectangle::writeInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Information about the Rectangle: \n";
  std::cout << "Width: " << rectangle.width << "\n";
  std::cout << "Heigth: " << rectangle.height << "\n";
  std::cout << "Center: (" << rectangle.pos.x << "," << rectangle.pos.y << ") \n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle: width = " << rectangle.width << " ,height = " << rectangle.height << "\n"
            << std::endl;
}

void bogdanov::Rectangle::scale(double scalingFactor)
{
  if (scalingFactor <= 0) {
    throw std::invalid_argument("Scaling factor must be positive");
  } else {
    rectangle_.width *= scalingFactor;
    rectangle_.height *= scalingFactor;
  }
}
