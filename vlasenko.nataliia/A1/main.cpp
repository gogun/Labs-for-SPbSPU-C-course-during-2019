#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "\t  //////////Rectangle//////////\n";
  Rectangle rectangle({3.5, 1.2}, 7, 9);
  Shape * shape = &rectangle;
  shape->printInfo();
  std::cout << "\t Transfer center of rectangle to (3.5+6.3, 1.2+7.3)\n";
  shape->move(6.3, 7.3);
  shape->printInfo();
  std::cout << "\t Move rectangle to (15.0, 21.9)\n";
  shape->move({15.0, 21.9});
  shape->printInfo();

  std::cout << "\t  ///////////Circle///////////\n";
  Circle circle({2.0, 5.2}, 8.4);
  shape = &circle;
  shape->printInfo();
  std::cout << "\t Transfer center of circle to (2.0+7.0, 5.2+1.0)\n";
  shape->move(7.0, 1.0);
  shape->printInfo();
  std::cout << "\t Move to (-16.1, 7.0)\n";
  shape->move({-16.1, 7.0});
  shape->printInfo();

  return 0;
}
