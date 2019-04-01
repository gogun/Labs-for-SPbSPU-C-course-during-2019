#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

int main()
{
  Rectangle rect({55, 55}, 10, 10);
  Circle circle({25, 25}, 5);
  Shape * shapeA = & rect, * shapeB = & circle;
  shapeA->move({5, 5});
  shapeB->move(-5, -5);
  std::cout << "Area of rectangle: " << shapeA->getArea() << std::endl;
  std::cout << "Area of circle: " << shapeB->getArea() << std::endl;
  std::cout << "position of rect: " << shapeA->getFrameRect().center.x 
      << ", " << shapeA->getFrameRect().center.y << std::endl;
  std::cout << "position of circle: " << shapeB->getFrameRect().center.x 
      << ", " << shapeB->getFrameRect().center.y << std::endl;
  return 0;
}
