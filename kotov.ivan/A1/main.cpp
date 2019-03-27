#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

int main()
{
  Rectangle rect({55, 55}, 10, 10);
  Circle circle({25, 25}, 5);
  Shape * a, * b;
  a = &rect;
  b = &circle;
  a->move(-5, -5);
  b->move(-5, -5);
  std::cout << "Area of rectangle: " << a->getArea() << std::endl;
  std::cout << "Area of circle: " << b->getArea() << std::endl;
  return 0;
}
