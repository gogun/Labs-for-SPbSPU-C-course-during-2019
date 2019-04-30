#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  borshchev::Rectangle rectangle({ 5, 5 }, 4, 6);
  borshchev::Shape *shape = &rectangle;
  shape->dataOutput();
  std::cout << "Rectangle's AREA: " << shape->getArea() << '\n';
  shape->move(8, 9);
  shape->move({ 2, 0 });
  shape->dataOutput();
  shape->scale(2.4);
  std::cout << "Rectangle's new AREA: " << shape->getArea() << '\n';

  borshchev::Circle circle({ 5, 5 }, 6);
  shape = &circle;
  shape->dataOutput();
  std::cout << "Circle's AREA: " << shape->getArea() << '\n';
  shape->move(4, 9);
  shape->move({ -3, 7 });
  shape->dataOutput();
  shape->scale(0.5);
  std::cout << "Circle's new AREA: " << shape->getArea() << '\n';

  return 0;
}
