#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Rectangle rectangleTest = {5.0, 3.5, {-1.0, -2.0}};
  Shape* shapeTest = &rectangleTest;
  std::cout << "That's what we know about shape:" << std::endl;
  shapeTest->printInfo();
  std::cout << "Let's move the shape 2 units left and 7.77 units up." << std::endl;
  shapeTest->move(-2.0, 7.77);
  shapeTest->printInfo();
  std::cout << "Now we will move the shape to a specific point (3, 4)." << std::endl;
  shapeTest->move({3.0, 4.0});
  shapeTest->printInfo();

  Circle circleTest = {2.5, {3.14, 2.71}};
  shapeTest = &circleTest;
  std::cout << "That's what we know about shape:" << std::endl;
  shapeTest->printInfo();
  std::cout << "Let's move the shape 2 units left and 7.77 units up." << std::endl;
  shapeTest->move(-2.0, 7.77);
  shapeTest->printInfo();
  std::cout << "Now we will move the shape to a specific point (3, 4)." << std::endl;
  shapeTest->move({3.0, 4.0});
  shapeTest->printInfo();

  Triangle triangleTest = {{13, 42}, {31, 28}, {25, 20}};
  shapeTest = &triangleTest;
  std::cout << "That's what we know about shape:" << std::endl;
  shapeTest->printInfo();
  std::cout << "Let's move the shape 2 units left and 7.77 units up." << std::endl;
  shapeTest->move(-2.0, 7.77);
  shapeTest->printInfo();
  std::cout << "Now we will move the shape to a specific point (3, 4)." << std::endl;
  shapeTest->move({3.0, 4.0});
  shapeTest->printInfo();

  return 0;
}
