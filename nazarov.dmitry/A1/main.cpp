#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rect_1({ 0, 0 }, 20, 10), rect_2({ 5, 5 }, 15, 20);
  Circle circle_1({ 10, 10 }, 10), circle_2({ 20, 20 }, 15);
  Shape * shapes[4] = { &rect_1, &circle_1, &rect_2, &circle_2 };

  std::cout << "Figures are at default positions\n\n";
  for (Shape * shape : shapes) {
    shape->printData();
  }

  rect_1.move(10, 20); 
  rect_2.move({ 4, 5 });
  circle_1.move(5, 6); 
  circle_2.move({ 0, 0 });

  std::cout << "Figures were moved to new positions\n\n";
  for (Shape * shape : shapes) {
    shape->printData();
  }

  return 0;
}
