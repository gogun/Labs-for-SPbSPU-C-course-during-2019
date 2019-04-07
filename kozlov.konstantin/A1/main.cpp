#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle circle(10, {4, 5});
  Shape * shape_link = &circle;
  std::cout << ">>Circle<<\n";
  shape_link->printData();
  std::cout << "-> Moving to x+= " << 10 << " and y+= " << 2 << std::endl;
  shape_link->move(10, 2);
  shape_link->printData();
  std::cout << std::endl;
  std::cout << "-> Moving to the point (" << 100 << "; " << 20 << ")\n";
  shape_link->move({100, 20});
  shape_link->printData();
  std::cout << std::endl;

  std::cout << "----------------------------\n" << std::endl;

  Rectangle rectangle({5, 7, {10, 10}});
  shape_link = &rectangle;
  std::cout << ">>Rectangle<<\n";
  shape_link->printData();
  std::cout << "-> Moving to x+= " << 5 << " and y+= " << 6 << std::endl;
  shape_link->move(5, 6);
  shape_link->printData();
  std::cout << std::endl;
  std::cout << "-> Moving to the point (" << 20 << "; " << 20 << ")\n";
  shape_link->move({20, 20});
  shape_link->printData();
  std::cout << std::endl;

  return 0;
}
