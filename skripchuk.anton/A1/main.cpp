#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  Rectangle rectangle({15, 10, {0, 0}});
  Shape * shapePtr = &rectangle;
  std::cout << "RECTANGLE:\n";
  shapePtr->show();
  std::cout << "Move to the point (" << 10 << "; " << 10 << ")\n";
  shapePtr->move({10, 10});
  shapePtr->show();
  std::cout << "Move at (" << 20 << "; " << 20 << ")\n";
  shapePtr->move(20, 20);
  shapePtr->show();
  std::cout << std::endl;

  Circle circle(10, {10, 10});
  shapePtr = &circle;
  std::cout << "CIRCLE:\n";
  shapePtr->show();
  std::cout << "Move to the point (" << 5 << "; " << 5 << ")\n";
  shapePtr->move({5, 5});
  shapePtr->show();
  std::cout << "Move at (" << 3 << "; " << 6 << ")\n";
  shapePtr->move(3, 6);
  shapePtr->show();
  std::cout << std::endl;

  Triangle triangle({0, 6}, {0, 0}, {6, 0});
  shapePtr = &triangle;
  std::cout << "TRIANGLE:\n";
  shapePtr->show();
  std::cout << "Move to the point (" << 15 << "; " << 15 << ")\n";
  shapePtr->move({15, 15});
  shapePtr->show();
  std::cout << "Move at (" << 4 << "; " << 7 << ")\n";
  shapePtr->move(4, 7);
  shapePtr->show();

  return 0;
}
