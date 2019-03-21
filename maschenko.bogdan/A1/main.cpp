#include <iostream>
#include <stdexcept>
#include <string>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Shape * shape;
  std::cout << "new Circle with center: (14;56) and radius = 5" << std::endl;

  Circle circle({14, 56}, 5);
  shape = &circle;
  shape->writeInfo();
  std::cout << "move Circle in point with center: (-34,32)" << std::endl;
  shape->move({-34, 32});
  shape->writeInfo();
  std::cout << "move Circle at the dx = 2, dy = -4" << std::endl;
  shape->move(2, -4);
  shape->writeInfo();

  try
  {
    Circle wrong_circle({14, 56}, -5);
  }
  catch (std::invalid_argument ia)
  {
    std::cout << ia.what() << std::endl;
  }

  std::cout << "-------------------------------------------------------------" << std::endl << std::endl;

  std::cout << "new Rectangle with center (-5;32) and width 2, height = 7" << std::endl;

  Rectangle rectangle({-5, 32}, 2, 7);
  shape->writeInfo();
  std::cout << "move Rectangle in point with center (-37,-37)" << std::endl;
  shape->move({-37, -37});
  shape->writeInfo();
  std::cout << "move Rectangle at the dx = 7, dy = 0" << std::endl;
  shape->move(7, 0);
  shape->writeInfo();

  try
  {
    Rectangle wrong_rectangle({-5, 32}, 2, -7);
  }
  catch (std::invalid_argument ia)
  {
    std::cout << ia.what() << std::endl;
  }

  return 0;
}
