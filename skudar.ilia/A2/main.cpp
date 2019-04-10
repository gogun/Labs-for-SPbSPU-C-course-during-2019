#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameRect(const skudar::Shape &shape)
{
  skudar::rectangle_t rect_tmp = shape.getFrameRect();
  std::cout << "Center: (" << rect_tmp.pos.x << ", "
      << rect_tmp.pos.y << ")" << std::endl
      << "Height = " << rect_tmp.height << std::endl
      << "Width = " << rect_tmp.width << std::endl
      << "Area = " << shape.getArea() << std::endl;
}

int main()
{
  skudar::Rectangle rect1({4, 4}, 3, 2); // create rectangle with center point (4, 4), width 3, height 2
  rect1.move({0, 0}); // move center of rect1 to point (0, 0)
  rect1.scale(2); // scale rectangle with a coefficient 2 => it'll be bigger
  std::cout << "1 rectangle:" << std::endl;
  printFrameRect(rect1);
  skudar::Rectangle rect2(10, 10, 10, 10); // create rectangle with coordinates (10, 10) and width 10, height 10
  rect1.scale(0.5); // scale rectangle with a coefficient 0.5 => it'll be less
  std::cout << "2 rectangle:" << std::endl;
  printFrameRect(rect2);
  skudar::Circle circ1({2, 4}, 6); // create circle with point (2, 4) and radius 6
  circle1.scale(1); // scale circle with a coefficient 1 => nothing will change
  circ1.move(4, 2); // now coordinates of center of circ1 is (6, 6)
  std::cout << "1 circle:" << std::endl;
  printFrameRect(circ1);
  skudar::Circle circ2(-4, 6, 9); // create circle with coordinates (-4, 6) and radius 9
  circ2.scale(1.5); // scale circle with a coefficient 1.5 => it'll be bigger
  std::cout << "2 circle:" << std::endl;
  printFrameRect(circ2);

  return 0;
}
