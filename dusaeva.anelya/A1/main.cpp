#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  //Rectangle
  Rectangle objRect({5.0,6.0}, 7.0, 1.0);
  Shape *shape = &objRect;

  std::cout << "Rectangle:" << std::endl;
  shape->printInfo();
  shape->move(5.0, 6.0);
  std::cout << "Coordinate shift:" << std::endl;
  shape->printInfo();
  shape->move({0.0, 3.0});
  std::cout << "Point shift:" << std::endl;
  shape->printInfo();
  std::cout << std::endl;
  //Circle
  Circle objCirc({1.0, 5.0}, 6.0);
  Shape *shapeC = &objCirc;

  std::cout << "Circle:" << std::endl;
  shapeC->printInfo();
  shapeC->move(1.0, 2.0);
  std::cout << "Coordinate shift:" << std::endl;
  shapeC->printInfo();
  shapeC->move({7.0, -9.0});
  std::cout << "Point shift:" << std::endl;
  shapeC->printInfo();
  std::cout << std::endl;

  return 0;
}
