#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main() {
  
  Rectangle rec({123,100},5,3);
  Shape* rectangle = &rec;
  rectangle->move(10,20);
  point_t tomove = {1,2};
  rectangle->move(tomove);
  std::cout << rectangle->getArea() << '\n';
  rectangle_t frame = rectangle->getFrameRect();
  std::cout << "Width of rectangle: " <<frame.width << '\n';
  std::cout << "Height of rectangle: " << frame.height <<'\n';

  Circle cir({11,12}, 4);
  Shape* circle = &cir;
  tomove = {10,20};
  circle->move(tomove);
  circle->move(1,2);
  std::cout << circle->getArea() << '\n';
  frame = circle->getFrameRect();
  std::cout << "Width of rectangle: " << frame.width << '\n';
  std::cout << "Height of rectangle: " << frame.height <<'\n';

  return 0;
}
