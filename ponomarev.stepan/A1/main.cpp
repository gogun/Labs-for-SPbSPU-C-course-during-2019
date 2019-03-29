#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "----Created new circle:----" << std::endl;
  Circle circle({-1.0, 1.0}, 2.0);
  Shape* shape = &circle;
  shape->info();
  std::cout << "-Moving to (22, -13)" << std::endl;
  shape->move({22.0, -13.0});
  shape->info();
  std::cout << "-Coords X += 1, y += 26" << std::endl;
  shape->move(1.0, 26.0);
  shape->info();

  std::cout << "\n";
  std::cout << "----Created new rectangle:----" << std::endl;
  Rectangle rectangle({121, 31}, 200, 1);
  shape = &rectangle;
  shape->info();
  std::cout << "-Moving to (81, -42)" << std::endl;
  shape->move({81, -42});
  shape->info();
  std::cout << "-Coords X -= 81, y += 42" << std::endl;
  shape->move(-81, 42);
  shape->info();

  return 0;
}
