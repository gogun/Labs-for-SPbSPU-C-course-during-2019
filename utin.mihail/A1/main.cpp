#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rect({4, 8}, 6, 7);
  Shape *shape = &rect;
  shape->printInfo();
  shape->move(4, 4);
  shape->printInfo();
  shape->move({1, 1});
  shape->printInfo();
  std::cout << "Area of rectangle is " << shape->getArea() << '\n';
  Circle circ({4, 8}, 6);
  shape = &circ;
  shape->printInfo();
  shape->move(5, 7);
  shape->printInfo();
  shape->move(2, 6);
  shape->printInfo();
  std::cout << "Area of Circle is " << shape->getArea() << '\n';
  return 0;
}
