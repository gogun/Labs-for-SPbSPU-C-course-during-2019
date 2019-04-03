#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectOne({ 0, 0 }, 100, 50);
  Shape *rectPointer = &rectOne;

  rectPointer->printInfo();
  rectPointer->move(10, 20);
  std::cout << "  Rectangle has been moved by dx and dy\n\n";
  rectPointer->printInfo();
  rectPointer->move({ 20, 40 });
  std::cout << "  Rectangle has been moved by coordinates\n\n";
  rectPointer->printInfo();

  Circle circleOne({ 0, 0 }, 50);
  Shape *circlePointer = &circleOne;

  circlePointer->printInfo();
  circlePointer->move(10, 20);
  std::cout << "  Circle has been moved by dx and dy\n\n";
  circlePointer->printInfo();
  circlePointer->move({20, 40});
  std::cout << "  Circle has been moved by coordinates\n\n";
  circlePointer->printInfo();

  return 0;
}
