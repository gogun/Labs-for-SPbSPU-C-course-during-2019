#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  //Rectangle
  Rectangle objRect({5.0, 6.0}, 7.0, 1.0);
  Shape *shape = &objRect;

  std::cout << "Rectangle:" << std::endl;
  shape->printInfo();
  shape->move(5.1, 6.2);
  std::cout << "Coordinate shift:" << std::endl;
  shape->printInfo();
  shape->move({0.0, 3.0});
  std::cout << "Point shift:" << std::endl;
  shape->printInfo();
  std::cout << std::endl;

  //Circle
  Circle objCirc({1.0, 5.0}, 6.0);
  shape = &objCirc;

  std::cout << "Circle:" << std::endl;
  shape->printInfo();
  shape->move(1.0, 2.0);
  std::cout << "Coordinate shift:" << std::endl;
  shape->printInfo();
  shape->move({7.8, -9.0});
  std::cout << "Point shift:" << std::endl;
  shape->printInfo();
  std::cout << std::endl;

  return 0;
}
