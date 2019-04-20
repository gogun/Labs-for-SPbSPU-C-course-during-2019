#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printShape(const Shape *shape)
{
  assert(shape != nullptr);
  shape->printData();
  std::cout << "\nArea: " << shape->getArea() << std::endl;
  rectangle_t frameRect = shape->getFrameRect();
  std::cout << "***Frame Rectangle:" << std::endl;
  std::cout << "Width: " << frameRect.width  << "\tHeight: " << frameRect.height;
  std::cout << "\nPosition: (" << frameRect.pos.x << ';' << frameRect.pos.y << ')';
}

int main()
{
  Rectangle rect1(5.2, 4, {2.4, -3});
  std::cout << "\nRectangle: \n";
  printShape(&rect1);

  const double dx = 1.6, dy = 4;
  rect1.move(dx, dy);
  std::cout << "\n===After move: + (" << dx << ';' << dy << ")\n";
  rect1.printData();

  std::cout << std::endl;

  Circle circ1(4, {3.2, 2.4});
  std::cout << "\nCircle: \n";
  printShape(&circ1);

  const point_t newPosCirc = {4.2, 3};
  circ1.move(newPosCirc);
  std::cout << "\n===After move: to (" << newPosCirc.x << ';' << newPosCirc.y << ")\n";
  circ1.printData();

  std::cout << std::endl;

  Triangle trian1({1.0, 0.5}, {2.0, 2.0}, {3.0, 0.5});
  std::cout << "\nTriangle: \n";
  printShape(&trian1);

  const point_t newPosTrian = {1, 6.7};
  trian1.move(newPosTrian);
  std::cout << "\n===After move: to (" << newPosTrian.x << ';' << newPosTrian.y << ")\n";
  trian1.printData();

  std::cout << std::endl;

  return 0;
}
