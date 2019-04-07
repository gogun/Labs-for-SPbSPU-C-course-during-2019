#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

void displayShape(const Shape *shape)
{
  assert(shape != nullptr);
  shape->displayData();
  std::cout << "\nArea: " << shape->getArea() << std::endl;
  rectangle_t frameRect = shape->getFrameRect();
  std::cout << "***Frame Rectangle:" << std::endl;
  std::cout << "Width: " << frameRect.width  << "\tHeight: " << frameRect.height;
  std::cout << "\nPosition: (" << frameRect.pos.x << ';' << frameRect.pos.y << ')';
}

int main()
{
  Rectangle rect1(5.2, 4, {2.4, -3});
  Shape *ptrShape = &rect1;
  std::cout << "Rectangle: \n";
  displayShape(ptrShape);

  const double deltaX = 1.6, deltaY = 4;
  ptrShape->move(deltaX, deltaY);
  std::cout << "\n===After move: + (" << deltaX << ';' << deltaY << ")\n";
  ptrShape->displayData();

  std::cout << std::endl;


  Circle circ1(4, {3.2, 2.4});
  ptrShape = &circ1;
  std::cout << "\nCircle: \n";
  displayShape(ptrShape);

  const point_t position = {4.2, 3};
  ptrShape->move(position);
  std::cout << "\n===After move: to (" << position.x << ';' << position.y << ")\n";
  ptrShape->displayData();

  std::cout << std::endl;
  return 0;
}
