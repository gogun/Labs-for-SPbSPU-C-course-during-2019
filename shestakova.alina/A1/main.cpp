#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printInfo(const Shape &shape)
{
  rectangle_t frame = shape.getFrameRect();
  std::cout << "Figure's center (" << frame.pos.x
            << "," << frame.pos.y << ")\n"
            <<"Rectangle frame width = " << frame.width
            <<"\nRectangle frame height = " << frame.height
            << ";\nArea = " << shape.getArea() << "\n";
}

int main()
{
  Rectangle rect({10, -2}, 8, 3);
  std::cout << "Created rectangle's parameters:\n";
  printInfo(rect);
  std::cout << "\nRectangle with a new centre at (4, 3):\n";
  rect.move({4, 3});
  printInfo(rect);
  std::cout << "\nRectangle shifted with dx=11, dy=0.9:\n";
  rect.move(11, 0.9);
  printInfo(rect);

  Circle circ({0.9, 2.3}, 3);
  std::cout << "\nCreated circle's parameters:\n";
  printInfo(circ);
  std::cout << "\nCircle with a new centre at (12, 11):\n";
  circ.move({12, 11});
  printInfo(circ);
  std::cout << "\nCircle shifted with dx=2.3, dy=4:\n";
  circ.move(2.3, 4);
  printInfo(circ);

  return 0;
}
