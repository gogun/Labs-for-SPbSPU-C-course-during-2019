#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

int main()
{
  Rectangle rect({55, 55}, 10, 10);
  Circle circle({25, 25}, 5);
  Shape ** shapes = new Shape*[2];
  shapes[0] = & rect; 
  shapes[1] = & circle;
  std::cout << "Area of " + shapes[0]->getShapeName() + ": " << shapes[0]->getArea() << std::endl;
  std::cout << "Area of " + shapes[1]->getShapeName() + ": " << shapes[1]->getArea() << std::endl;
  std::cout << "position of " + shapes[0]->getShapeName() + ": " << shapes[0]->getFrameRect().pos.x 
      << ", " << shapes[0]->getFrameRect().pos.y << std::endl;
  std::cout << "position of " + shapes[1]->getShapeName() + ": " << shapes[1]->getFrameRect().pos.x 
      << ", " << shapes[1]->getFrameRect().pos.y << std::endl;
  shapes[0]->move(-5, -5);
  shapes[1]->move({5, 5});
  std::cout << "Area of " + shapes[0]->getShapeName() + " after moving: " << shapes[0]->getArea() << std::endl;
  std::cout << "Area of " + shapes[1]->getShapeName() + " after moving: " << shapes[1]->getArea() << std::endl;
  std::cout << "position of " + shapes[0]->getShapeName() + " after moving: " << shapes[0]->getFrameRect().pos.x
      << ", " << shapes[0]->getFrameRect().pos.y << std::endl;
  std::cout << "position of " + shapes[1]->getShapeName() + " after moving: " << shapes[1]->getFrameRect().pos.x
      << ", " << shapes[1]->getFrameRect().pos.y << std::endl;
  delete shapes;
  return 0;
}
