#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameRect(const Shape &shape)
{
  rectangle_t rect_tmp = shape.getFrameRect();
  std::cout << "Center: (" << rect_tmp.pos.x << ", "
            << rect_tmp.pos.y << ")" << std::endl
            << "Height = " << rect_tmp.height << std::endl
            << "Width = " << rect_tmp.width << std::endl
            <<"Area = " << shape.getArea() << std::endl; // changed from rect_tmp to shape
}

int main() {
  Rectangle rect1({4, 4}, 3, 2); // create rectangle with center point (4, 4), width 3, height 2
  rect1.move({0, 0}); // move center of rect1 to point (0, 0)
  std::cout << "1 rectangle:" << std::endl;
  printFrameRect(rect1);
  Rectangle rect2(10, 10, 10, 10); // create rectangle with
  std::cout << "2 rectangle:" << std::endl;
  printFrameRect(rect2);
  Circle circ1({2, 4}, 6); // create circle with point (2, 4) and radius 6
  circ1.move(4, 2); // now coordinates of center of circ1 is (6, 6)
  std::cout << "1 cercle:" << std::endl;
  printFrameRect(circ1);
  Circle circ2(-4, 6, 9); // create circle with coordinates (-4, 6) and radius 9
  std::cout << "2 cercle:" << std::endl;
  printFrameRect(circ2);
  return 0;
}
