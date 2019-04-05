#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void printFrameRect(const Shape& shape)
{
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << frameRect.pos.x << " "
      << frameRect.pos.y << " "
      << frameRect.width << " "
      << frameRect.height << std::endl;
}

int main() {
  Circle c1({4, 5}, 6);
  c1.move(2, 2);
  std::cout << c1.getArea() << std::endl;

  Circle c2({5, 6}, 7);
  c2.move({3, 3});

  Rectangle r1({1, 2}, 4, 5);
  r1.move({5, 5});
  std::cout << r1.getArea() << std::endl;

  Rectangle r2({2, 3}, 5, 6);
  r2.move(2, 2);

  printFrameRect(c2);
  printFrameRect(r2);

  return 0;
}
