#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "----Created new circle:----\n";
  Circle circle({-1.0, 1.0}, 2.0);
  Shape* shape(&circle);
  shape->getInfo();
  std::cout << "-Moving to (22, -13)\n";
  shape->move({22.0, -13.0});
  shape->getInfo();
  std::cout << "-Coords X += 1, y += 26\n";
  shape->move(1.0, 26.0);
  shape->getInfo();

  std::cout << std::endl;

  std::cout << "----Created new rectangle:----\n";
  Rectangle rectangle({121, 31}, 200, 1);
  shape = &rectangle;
  shape->getInfo();
  std::cout << "-Moving to (81, -42)\n";
  shape->move({81, -42});
  shape->getInfo();
  std::cout << "-Coords X -= 81, y += 42\n";
  shape->move(-81, 42);
  shape->getInfo();

  return 0;
}
