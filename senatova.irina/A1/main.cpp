#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"


int main()
{
  Circle circle({6, -4}, 15.3);
  Shape * shape = &circle;
  std::cout << "Circle info\n";
  shape -> print();
  std::cout << "Add to Ox " << 3 << " and to Oy " << 2 << std::endl;
  shape -> move(3, 2);
  shape -> print();
  std::cout << "Move to (" << 29 << ", " << 13 << ")\n";
  shape -> move({29, 13});
  shape -> print();


  Rectangle rectangle({3, 6}, 5, 8);
  shape = &rectangle;
  std::cout << "Rectangle info\n";
  shape -> print();
  std::cout << "Move to (" << 15 << ", " << 10 << ")\n";
  shape -> move({15, 10});
  shape -> print();
  std::cout << std::endl;
  return 0;
}
