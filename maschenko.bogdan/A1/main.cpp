#include <iostream>
#include <string>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  std::cout << "new Circle with center: (14;56) and radius = 5" << std::endl;
  try
  {
    Circle circle({14, 56}, -5);
    circle.writeInfo();
    std::cout << "move Circle in point with center: (-34,32)" << std::endl;
    circle.move({-34, 32});
    circle.writeInfo();
    std::cout << "move Circle at the dx = 2, dy = -4" << std::endl;
    circle.move(2, -4);
    circle.writeInfo();
  }
  catch (std::string message)
  {
    std::cout << message << std::endl;
    return 2;
  }

  std::cout << "-------------------------------------------------------------" << std::endl << std::endl;

  std::cout << "new Rectangle with center (-5;32) and width 2, height = 7" << std::endl;
  try
  {
    Rectangle rectangle({-5, 32}, 2, 7);
    rectangle.writeInfo();
    std::cout << "move Rectangle in point with center (-37,-37)" << std::endl;
    rectangle.move({-37, -37});
    rectangle.writeInfo();
    std::cout << "move Rectangle at the dx = 7, dy = 0" << std::endl;
    rectangle.move(7, 0);
    rectangle.writeInfo();
  }
  catch (std::string message)
  {
    std::cout << message << std::endl;
    return 2;
  }

  std::cout << "-------------------------------------------------------------" << std::endl << std::endl;

  std::cout << "new Triangle with side a: (0;0), side b: (0;34), side c: (15;25)" << std::endl;
  try
  {
    Triangle triangle({0, 0}, {0, 34}, {15, 25});
    triangle.writeInfo();
    std::cout << "move Triangle in point with center (-12,87)" << std::endl;
    triangle.move({-12, -87});
    triangle.writeInfo();
    std::cout << "move Triangle at the dx = 10, dy = 10" << std::endl;
    triangle.move(10, 10);
    triangle.writeInfo();
  }
  catch (std::string message)
  {
    std::cout << message << std::endl;
    return 2;
  }
}
