#include "rectangle.cpp"
#include "circle.cpp"

#include <iostream>

int main()
{
  Rectangle rectangle(3.3, 4.8, {4.5, 2.8});
  rectangle.printInfo();
  rectangle.move(5.3, 8.0);
  std::cout << "After moving dx = 5.3, dy = 8.0: \n";
  rectangle.printInfo();
  rectangle.move({10.0, 2.3});
  std::cout << "After moving to a point with coordinates {10, 2.3}: \n";
  rectangle.printInfo();

  std::cout << "New rectangle \n";
  Rectangle shapeRectangle(5.6, 6.9, {4.1, 4.4});
  Shape * shape = &shapeRectangle;
  shape->getFrameRect();
  shape->printInfo();
  shape->move(6.3, 10.2);
  std::cout << "After moving dx = 6.3, dy = 10.2: \n";
  shape->printInfo();
  shape->move({2.2, 3.0});
  std::cout << "After moving to a point with coordinates {2.2, 3}: \n";
  shape->printInfo();

  Circle circle(2.9, {4.0, 3.0});
  circle.printInfo();
  circle.move(2.0, 6.5);
  std::cout << "After moving dx = 2, dy = 6.5: \n";
  circle.printInfo();
  circle.move({7.0, 12.2});
  std::cout << "After moving to a point with coordinates {7, 12.2}: \n";
  circle.printInfo();

  return 0;
}
