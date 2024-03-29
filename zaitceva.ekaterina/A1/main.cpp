#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printRect(const Shape &shape)
{
  const rectangle_t rectangle1 = shape.getFrameRect();
  std::cout << rectangle1.width << " " << rectangle1.height;
  std::cout << " " << "(" << rectangle1.pos.x << "," <<rectangle1.pos.y << ")" << std::endl;
}

void showProgramWork(Shape &shape)
{
  std::cout << "Rectangle frame: ";
  printRect(shape);
  std::cout << "Area = " << shape.getArea() << std::endl;
  shape.move({2, 1});
  std::cout << "After moving to a point: " << std::endl;
  printRect(shape);
  shape.move(2, 8);
  std::cout << "After axial movement: " << std::endl;
  printRect(shape);
}

int main()
{
  std::cout << "Rectangle" << std::endl;
  Rectangle rectangle(6, 9, {3, 4});
  showProgramWork(rectangle);

  std::cout << "Circle" << std::endl;
  Circle circle({5, 5}, 4);
  showProgramWork(circle);

  std::cout << "Triangle" << std::endl;
  Triangle triangle({-1, -1},{-1, -4},{-5, -1});
  triangle.printTriangle();
  std::cout << "Rectangle frame: ";
  printRect(triangle);
  std::cout << "Area = " << triangle.getArea() << std::endl;
  triangle.move({1, 1});
  std::cout << "After moving to a point: " << std::endl;
  triangle.printTriangle();
  triangle.move(2, 8);
  std::cout << "After axial movement: " << std::endl;
  triangle.printTriangle();

  return 0;
}
