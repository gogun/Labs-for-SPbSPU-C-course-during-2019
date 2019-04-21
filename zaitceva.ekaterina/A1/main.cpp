#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printRect(Shape &shape)
{
  rectangle_t rectangle1 = shape.getFrameRect();
  std::cout << rectangle1.width << " " << rectangle1.height;
  std::cout << " " << "(" << rectangle1.pos.x << "," <<rectangle1.pos.y << ")" << std::endl;
}

int main()
{
  std::cout << "Rectangle" << std::endl;
<<<<<<< HEAD
  Rectangle rectangle (6, 9, {3, 4});
=======
  Rectangle rectangle(6,9,{3,4});
>>>>>>> cff4620426758ab4f71da736ce185299208621be
  printRect(rectangle);
  std::cout << "Area = " << rectangle.getArea() << std::endl;
  rectangle.move({2, 1});
  std::cout << "After moving to a point: ";
  printRect(rectangle);
  rectangle.move(2, 8);
  std::cout << "After axial movement: ";
  printRect(rectangle);

  std::cout << "Circle" << std::endl;
<<<<<<< HEAD
  Circle circle ({5, 5}, 4);
=======
  Circle circle({5,5},4);
>>>>>>> cff4620426758ab4f71da736ce185299208621be
  std::cout << "Rectangle frame: ";
  printRect(circle);
  std::cout << "Area = " << circle.getArea() << std::endl;
  circle.move({1, 1});
  std::cout << "After moving to a point: ";
  printRect(circle);
  circle.move(2, 8);
  std::cout << "After axial movement: ";
  printRect(circle);

  std::cout << "Triangle" << std::endl;
<<<<<<< HEAD
  Triangle triangle ({-1, -1},{-1, -4},{-5, -1});
=======
  Triangle triangle({-1,-1},{-1,-4},{-5,-1});
>>>>>>> cff4620426758ab4f71da736ce185299208621be
  triangle.printTriang();
  std::cout << "Rectangle frame: ";
  printRect(triangle);
  std::cout << "Area = " << triangle.getArea() << std::endl;
  triangle.move({1, 1});
  std::cout << "After moving to a point: " << std::endl;
  triangle.printTriang();
  triangle.move(2, 8);
  std::cout << "After axial movement: " << std::endl;
  triangle.printTriang();

  return 0;
};
