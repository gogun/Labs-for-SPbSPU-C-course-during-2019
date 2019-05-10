#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  sheve::Rectangle rec({ 20, 10 }, 15, 50);
  sheve::Circle cir({ 20, 30 }, 13);
  sheve::Triangle tri({ 12, -12 }, { 13, 3 }, { 1, 23 });

  sheve::Shape * shape = &rec;
  std::cout << "Rectangle before changes:" << std::endl;
  shape->printInfo();
  shape->move({ -27, 52 });
  shape->move(10, -30);
  shape->scale(1.2);
  std::cout << "Rectangle after changes:" << std::endl;
  shape->printInfo();

  shape = &cir;
  std::cout << "Circle before changes:" << std::endl;
  shape->printInfo();
  shape->move({ 32, -6 });
  shape->move(-12, 9);
  shape->scale(4.0);
  std::cout << "Circle after changes:" << std::endl;
  shape->printInfo();

  shape = &tri;
  std::cout << "Triangle before changes:" << std::endl;
  shape->printInfo();
  shape->move({ -7, 4 });
  shape->move(10, 20);
  shape->scale(1.63);
  std::cout << "Triangle after changes:" << std::endl;
  shape->printInfo();

  return 0;
}
