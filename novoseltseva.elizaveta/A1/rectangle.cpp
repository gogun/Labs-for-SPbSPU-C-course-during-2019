#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle(float width, float height, float x, float y)
{
  object.pos.x = x; object.pos.y = y;
  object.width = width; object.height = height;
  std::cout << "Rectangle default Param:" << std::endl
      << "Width = " << object.width << " Height = " << object.width << std::endl
      << "X = " << object.pos.x << " Y = " << object.pos.y << std::endl;
}

void Rectangle::getArea() const
{
  std::cout << "Space: " << object.width * object.height << std::endl;
}
