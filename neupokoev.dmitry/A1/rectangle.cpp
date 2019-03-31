#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(rectangle_t parameters) :
  parameters_(parameters)
{
  assert((parameters_.height > 0.0));
  assert((parameters_.width > 0.0));
}

double Rectangle::getArea() const
{
  return parameters_.width * parameters_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return parameters_;
}

void Rectangle::move(const point_t &dot)
{
  parameters_.pos = dot;
}

void Rectangle::move(double moveX, double moveY)
{
  parameters_.pos.x += moveX;
  parameters_.pos.y += moveY;
}

void Rectangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle centre is (" << parameters_.pos.x << "," << parameters_.pos.y << ")\n";
  std::cout << "Frame rectangle width = " << rectangle.width << ", height = " << rectangle.height << "\n";
  std::cout << "Area = " << getArea() << "\n\n";
}
