#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

void printShape(const Shape *shape)
{
  assert(shape != nullptr);
  shape->printData();
  std::cout << "\nArea: " << shape->getArea() << std::endl;
  rectangle_t frameRect = shape->getFrameRect();
  std::cout << "***Frame Rectangle:" << std::endl
    << "Width: " << frameRect.width  << "\tHeight: " << frameRect.height
        << "\nPosition: (" << frameRect.pos.x << ';' << frameRect.pos.y << ')';
}

int main()
{
  Rectangle rect1(7.2, 5.7, {5, -2.4});
  std::cout << "Rectangle:"
    << "\n*******************";
  printShape(&rect1);

  const double dx = 2.5, dy = -4.1;
  rect1.move(dx, dy);
  std::cout << "\n===After move: + (" << dx << ';' << dy << ")===";
  rect1.printData();
  std::cout << std::endl;

  Circle circ1(5);
  std::cout << "\nCircle:"
    << "\n*******************";
  printShape(&circ1);

  const point_t position = {-1.8, 2.4};
  circ1.move(position);
  std::cout << "\n===After move to (-1.8, 2.4)===";
  circ1.printData();

  std::cout << std::endl;
  return 0;
}
