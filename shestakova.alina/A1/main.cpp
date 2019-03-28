#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printInfo(const Shape &shape)
{
  rectangle_t frame = shape.getFrameRect();
  std::cout << "Figure's center (" << frame.pos.x
            << "," << frame.pos.y << ")\n"
            <<"Rectangle frame width = " << frame.width
            <<"\nFigure frame height = " << frame.height
            << ";\nArea = " << shape.getArea() << "\n";
}

int main()
{
  Rectangle rect({10, -2}, 8, 3);
  Shape * shape = &rect;
  std::cout << "Created rectangle's parameters:\n";
  printInfo(* shape);
  std::cout << "\nRectangle with a new centre at (4, 3):\n";
  shape->move({4, 3});
  printInfo(* shape);
  std::cout << "\nRectangle shifted with dx=11, dy=0.9:\n";
  shape->move(11, 0.9);
  printInfo(* shape);

  Circle circ({0.9, 2.3}, 3);
  shape = &circ;
  std::cout << "\nCreated circle's parameters:\n";
  printInfo(circ);
  std::cout << "\nCircle with a new centre at (12, 11):\n";
  shape->move({12, 11});
  printInfo(* shape);
  std::cout << "\nCircle shifted with dx=2.3, dy=4:\n";
  shape->move(2.3, 4);
  printInfo(* shape);

  return 0;
}
