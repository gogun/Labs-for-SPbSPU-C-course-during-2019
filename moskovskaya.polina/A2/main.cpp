#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

void printRectFrames(const moskovskaya::Shape *shape)
{
  assert(shape != nullptr);
  moskovskaya::rectangle_t frameRect = shape->getFrameRect();
  std::cout << "{" << frameRect.pos.x << ","
      << frameRect.pos.y << "},"
      << frameRect.width << ","
      << frameRect.height << "\n";
}

int main()
{
  moskovskaya::Rectangle rec1({3, 2}, 1, 8);
  rec1.move(5, 8);
  std::cout << rec1.getArea() << "\n";

  printRectFrames(&rec1);

  moskovskaya::Rectangle rec2({2, 1}, 4, 2);
  rec2.move({2, 1});

  printRectFrames(&rec2);

  moskovskaya::Rectangle rec3({1, 4}, 2, 2);
  rec3.scale(5);

  printRectFrames(&rec3);

  moskovskaya::Circle cir1({1, 7}, 5);
  cir1.move({3, 5});
  std::cout << cir1.getArea() << "\n";

  printRectFrames(&cir1);

  moskovskaya::Circle cir2({8, 4}, 4);
  cir2.move(4, 3);

  printRectFrames(&cir2);

  moskovskaya::Circle cir3({3, 5}, 4);
  cir3.scale(1.6);

  printRectFrames(&cir3);

  return 0;
}
