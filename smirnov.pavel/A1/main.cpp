#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "WORK WITH RECTANGLE:\n";
  Rectangle rect(20, 10, {5, 7});
  Shape *basePointer = &rect;
  std::cout << "Before first moving\n";
  basePointer->getInfo();
  basePointer->move({ 4, 9 });
  std::cout << "After first moving\n";
  basePointer->getInfo();
  basePointer->move(10, 5);
  std::cout << "After second moving\n";
  basePointer->getInfo();

  std::cout << "WORK WITH CIRCLE:\n";
  Circle circ(6, { 10, 5 });
  basePointer = &circ;
  std::cout << "Before first moving\n";
  basePointer->getInfo();
  basePointer->move({15, 20});
  std::cout << "After first moving\n";
  basePointer->getInfo();
  basePointer->move(-7, 12);
  std::cout << "After second moving\n";
  basePointer->getInfo();

  return 0;
}
