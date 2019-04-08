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
  Circle circ1(4, {3.2, 2.4});
  std::cout << "\nCircle: \n";
  displayShape(circ1);

  const point_t newPos = {4.2, 3};
  circ1.move(newPos);
  std::cout << "\n===After move: to (" << newPos.x << ';' << newPos.y << ")\n";
  circ1.displayData();

  std::cout << std::endl;

  Rectangle rect1(5.2, 4, {2.4, -3});
  std::cout << "Rectangle: \n";
  displayShape(rect1);

  const double dx = 1.6, dy = 4;
  rect1.move(dx, dy);
  std::cout << "\n===After move: + (" << dx << ';' << dy << ")\n";
  rect1.displayData();

  std::cout << std::endl;

  return 0;
}
