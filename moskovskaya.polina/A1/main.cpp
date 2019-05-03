#include <iostream>
#include <cassert>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printRectFrames(const Shape *shape)
{
  assert(shape != nullptr);
  rectangle_t frameRect = shape->getFrameRect();
  std::cout << "{" << frameRect.pos.x << ","
      << frameRect.pos.y << "},"
      << frameRect.width << ","
      << frameRect.height << "\n";
}

int main()
{
  Rectangle rec1({3, 2}, 1, 8);
  rec1.move({5, 8});
  std::cout << rec1.getArea() << "\n";

  Rectangle rec2({2, 1}, 4, 2);
  rec2.move({2, 1});

  printRectFrames(&rec2);

  Circle cir1({1, 7}, 5);
  cir1.move(3, 5);
  std::cout << cir1.getArea() << "\n";

  Circle cir2({8, 4}, 4);
  cir2.move(4, 3);

  printRectFrames(&cir2);

  return 0;
}
