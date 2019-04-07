<<<<<<< HEAD
=======
#include "rectangle.hpp"
#include "circle.hpp"

>>>>>>> 8b73dd0dfd665a3fbfd58ca13ab9ece3d33c884d
#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

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

  std::cout << "New circle \n";
  Circle shapeCircle(6.1, {2.0, 10.5});
  shape = &shapeCircle;
  shape->getFrameRect();
  shape->printInfo();
  shape->move(5.1, 4.0);
  std::cout << "After moving dx = 5.1, dy = 4.0: \n";
  shape->printInfo();
  shape->move({10.1, 1.9});
  std::cout << "After moving to a point with coordinates {10.1, 1.9}: \n";
  shape->printInfo();

  return 0;
}
