#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "----Rectangle----\n";
  Rectangle rect({5.3,5.2},15,10);
  Shape * shape = &rect;
  shape->printInfo();
  std::cout << "Shift to (2.3,2.5)!\n";
  shape->move(2.3,2.5);
  shape->printInfo();
  std::cout << "Move to (10,24)!\n";
  shape->move({10,24});
  shape->printInfo();

  std::cout << "----Circle----\n";
  Circle circle({3,3.5},5.7);
  shape = &circle;
  shape->printInfo();
  std::cout << "Shift to (7,1)!\n";
  shape->move(7,1);
  shape->printInfo();
  std::cout << "Move to (-27,9)!\n";
  shape->move({-27,9});
  shape->printInfo();

  return 0;
}

