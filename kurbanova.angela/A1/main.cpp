#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  std::cout << "Circle with center: (32;-15) and radius = 7" << std::endl;
  Circle circle({32, -15}, 7);
  Shape * shape = &circle;
  shape->printInfo();
  std::cout << "move Circle in point: (10,12)" << std::endl;
  shape->move({10, 12});
  shape->printInfo();
  std::cout << "move Circle at the dx = -3, dy = -8" << std::endl;
  shape->move(-3, -8);
  shape->printInfo();

  std::cout << "" << std::endl;

  std::cout << "Rectangle with center (32;-15) and width = 5, height = 4" << std::endl;
  Rectangle rectangle({32, -15}, 5, 4);
  shape = &rectangle;
  shape->printInfo();
  std::cout << "move Rectangle in point with center (10,21)" << std::endl;
  shape->move({10, 21});
  shape->printInfo();
  std::cout << "move Rectangle at the dx = -4, dy = 2" << std::endl;
  shape->move(-4, 2);
  shape->printInfo();

  return 0;
}
