#include <iostream>
#include "Circle.hpp"

Circle::Circle(float width, float height, float x, float y)
{
  object.width = width; object.height = height;
  object.pos.x = x; object.pos.y = y;
  std::cout << "Circle default Param:" << std::endl
      << "Width = " << object.width << " Height = " << object.width << std::endl
      << "X = " << object.pos.x << " Y = " << object.pos.y << std::endl;
}

void Circle::getArea() const
{
  std::cout << "Space: " << (object.width / 2) * (object.height / 2) * PI << std::endl;
}
