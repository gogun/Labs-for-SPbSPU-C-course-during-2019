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
  std::cout << "Area of rectangle: " << shapeA->getArea() << std::endl;
  std::cout << "Area of circle: " << shapeB->getArea() << std::endl;
  std::cout << "position of rect: " << shapeA->getFrameRect().pos.x 
      << ", " << shapeA->getFrameRect().pos.y << std::endl;
  std::cout << "position of circle: " << shapeB->getFrameRect().pos.x 
      << ", " << shapeB->getFrameRect().pos.y << std::endl;
  shapeA->move(-5, -5);
  shapeB->move({5, 5});
  std::cout << "Area of rectangle after moving: " << shapeA->getArea() << std::endl;
  std::cout << "Area of circle after moving: " << shapeB->getArea() << std::endl;
  std::cout << "position of rect after moving: " << shapeA->getFrameRect().pos.x 
      << ", " << shapeA->getFrameRect().pos.y << std::endl;
  std::cout << "position of circle after moving: " << shapeB->getFrameRect().pos.x 
      << ", " << shapeB->getFrameRect().pos.y << std::endl;
  return 0;
}
