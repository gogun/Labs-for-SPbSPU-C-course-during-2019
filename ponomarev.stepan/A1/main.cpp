#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "----Created new circle:----" << std::emdl;
  Circle circle{(-1, 1), 2};
  Shape* shape = &circle;
  shape->info();
  std::cout << "-Moving to (22, -13)" << std::endl;
  shape->move((22,-13));
  shape->info();
  std::cout << "-Coords X += 1, y += 26" << std::endl;
  shape->move(1, 26);
  shape->info();

  std::cout << "\n";
  std::cout << "----Created new rectangle:----" << std::emdl;
  Rectangle rectangle{(13, 0), 200, 1};
  shape = &rectangle;
  shape->info();
  std::cout << "-Moving to (81, -42)" << std::endl;
  shape->move((81, -42));
  shape->info();
  std::cout << "-Coords X -= 81, y += 42" << std::endl;
  shape->move(-81, 42);
  shape->info();
  
  return 0;
}
