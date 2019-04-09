#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectangle({5, 5}, 4, 6);
  Shape *shape = &rectangle;
  shape->dataOutput();
  std::cout << "Rectangle's AREA: " << shape->getArea() << '\n';
  shape->move(8, 9);
  shape->move({2, 0});
  shape->dataOutput();
  Circle circle({5, 5}, 6);
  shape = &circle;
  shape->dataOutput();
  std::cout << "Circle's AREA: " << shape->getArea() << '\n';
  shape->move(4, 9);
  shape->move({-3, 7});
  shape->dataOutput();

  return 0;
}
