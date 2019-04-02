#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle({12, 12}, 12);
  circle.printInf();
  // Move to point{23,45}
  circle.move({23, 45});
  std::cout << "Parameters of circle after move: " << std::endl;
  circle.printInf();

  // Move to x = 45, y = 12
  circle.move(45, 12);
  std::cout << "Parameters of circle after move: " << std::endl;
  circle.printInf();

  Rectangle rectangle(12, 34, 23 , 56);
  rectangle.printInf();
  // Move to point{67,78}
  rectangle.move({67, 78});
  std::cout << "Parameters of rectangle after move: " << std::endl;
  rectangle.printInf();

  // Move to x = 17, y = 34
  rectangle.move(17, 34);
  std::cout << "Parameters of rectangle after move: " << std::endl;
  rectangle.printInf();
  
  return 0;
}

