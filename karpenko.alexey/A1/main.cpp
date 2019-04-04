#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"


void printRectangle(const Shape &shape)
{
  rectangle_t fRect = shape.getFrameRect();
  std::cout << "Width is " << fRect.width;
  std::cout << "; Height is " << fRect.height << ";\n";
  std::cout << "Center on [" << fRect.pos.x << ";" << fRect.pos.y << "];\n";
  std::cout << "Area of rectangle is " << shape.getArea() << ";\n\n";
}

void printCircle(const Shape &shape)
{
  rectangle_t fRect = shape.getFrameRect();
  std::cout << "Width of frame circle rectangle is " << fRect.width;
  std::cout << "; Height of frame circle rectangle is " << fRect.height << ";\n";
  std::cout << "Center on [" << fRect.pos.x << ";" << fRect.pos.y << "];\n";
  std::cout << "Area of circle is " << shape.getArea() << ";\n\n";
}

int main()
{
  Rectangle rectangle({1, 4, {3, 4}});
  std::cout << "Rectangle demonstration started.\n\n";
  printRectangle(rectangle);
  std::cout << "Moving to coordinates...\n";
  rectangle.move(5, 6);
  printRectangle(rectangle);
  std::cout << "Moving to point...\n";
  rectangle.move({3, 3});
  printRectangle(rectangle);
  std::cout << "End program for Rectangle;\n\n";

  Circle circle({6, {1, 2}});
  std::cout << "Circle demonstration started.\n";
  printCircle(circle);
  std::cout << "Moving to coordinates...\n";
  circle.move(5, 6);
  printCircle(circle);
  std::cout << "Moving to point...\n";
  circle.move({3, 3});
  printCircle(circle);
  std::cout << "End program for Circle;\n";
  return 0;
}
