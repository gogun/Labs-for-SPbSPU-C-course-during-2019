#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

void printShape(const Shape * shapePtr)
{
  assert (shapePtr);

  shapePtr->printInfo();
  std::cout << std::endl;
}

int main()
{
  Circle circle1({56, 10}, 8);
  std::cout << "Creating the first circle at {56, 10}, radius = 8" << std::endl;
  circle1.move({5, 5});
  Circle circle2({47, 12.3}, 5.7);
  std::cout << "Creating the first circle at {47, 12.3}, radius = 5.7" << std::endl;
  circle2.move(5.8, 2.7);
  Rectangle rectangle1({0, 0}, 5, 5.5);
  std::cout << "Creating the first rectangle at {0, 0}, width = 5, height = 5.5" << std::endl;
  rectangle1.move({3, 7.9});
  Rectangle rectangle2({5, 12}, 0.2, 4);
  std::cout << "Creating the first rectangle at {5, 12}, width = 0.2, height = 4" << std::endl;
  rectangle2.move(0.5, 31);
  std::cout << std::endl;

  Shape * shapes[4] = {&circle1, &rectangle1, &circle2, &rectangle2};
  for (Shape * shape : shapes)
  {
    printShape(shape);
  }

  return 0;
}
