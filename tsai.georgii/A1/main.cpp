#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectOne({ 0, 0 }, 100, 50);
  Shape *shapePointer = &rectOne;

  shapePointer->printInfo();
  shapePointer->move(10, 20);
  std::cout << "  Rectangle has been moved by dx and dy\n\n";
  shapePointer->printInfo();
  shapePointer->move({ 20, 40 });
  std::cout << "  Rectangle has been moved by coordinates\n\n";
  shapePointer->printInfo();

  Circle circleOne({ 0, 0 }, 50);
  shapePointer = &circleOne;

  shapePointer->printInfo();
  shapePointer->move(10, 20);
  std::cout << "  Circle has been moved by dx and dy\n\n";
  shapePointer->printInfo();
  shapePointer->move({20, 40});
  std::cout << "  Circle has been moved by coordinates\n\n";
  shapePointer->printInfo();

  return 0;
}
