#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main ()
{
  std::cout << "------Rectangle------\n";
  Rectangle rect({7.1,7.3},13.0,17.0);
  Shape * shape = &rect;
  shape -> printInfo();
  std::cout << "Shift to (3.2,3.6)\n";
  shape -> move(3.2,3.6);
  std::cout << "Move to (14,30)\n";
  shape -> move({14.0,30.0});
  shape -> printInfo();

  std::cout << "-------Circle-------\n";
  Circle circle({4.2,4.8},8.8);
  shape = &circle;
  shape -> printInfo();
  std::cout << "Shift to (8,2)\n";
  shape -> move(8.0,2.0);
  shape -> printInfo();
  std::cout << "Move to (21,-9)\n";
  shape -> move({21.0,-9.0});
  shape -> printInfo();

  return 0;
}