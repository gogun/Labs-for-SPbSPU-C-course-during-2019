#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"


void printInfo(const Shape *shape)
{
  assert(shape != nullptr);
  const rectangle_t tempRect = shape->getFrameRect();

  std::cout << "Width: " << tempRect.width << '\n';
  std::cout << "Height: " << tempRect.height << '\n';
  std::cout << "Center: (" << tempRect.pos.x << ',' << tempRect.pos.y << ")\n";
  std::cout << "Area: " << shape->getArea() << '\n';
}

int main()
{
  Rectangle rect({2.6,4.4}, 15.0, 20.0); //Rectangle with center is (2.6,4.4) , width 15 , height 20
  Shape * shape = &rect;

  std::cout << "-----Rectangle-----\n";
  printInfo(shape);

  std::cout << "\nShift (1.7,-1.3):\n";
  shape->move(1.7,-1.3);
  printInfo(shape);

  std::cout << "\nMove to (2.3,5.8):\n";
  shape->move({2.3,5.8});
  printInfo(shape);

  Circle cirle({7.2,6.8}, 10.0); //Circle whit center is (7.2,6.8) , radius 10
  shape = &cirle;

  std::cout << "\n-----Circle-----\n";
  printInfo(shape);

  std::cout << "\nShift (1.0,2.0):\n";
  shape->move(1.0,2.0);
  printInfo(shape);

  std::cout << "\nMove to (5.3,4.1):\n";
  shape->move({5.3,4.1});
  printInfo(shape);

  return 0;
}
