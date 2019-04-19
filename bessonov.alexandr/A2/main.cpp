#include <iostream>
#include <cassert>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printRectFrames(const bessonov::Shape *shape)
{
  assert(shape != nullptr);
  bessonov::rectangle_t frameRect = shape->getFrameRect();
  std::cout << "{" << frameRect.pos.x << ","
      << frameRect.pos.y << "},"
      << frameRect.width << ","
      << frameRect.height << "\n";
}

int main()
{
  bessonov::Rectangle rec1({ 3, 2 }, 1, 8);
  rec1.move({ 5, 8 });
  std::cout << rec1.getArea() << "\n";

  printRectFrames(&rec1);

  bessonov::Rectangle rec2({ 2, 1 }, 4, 2);
  rec2.move({ 2, 1 });

  printRectFrames(&rec2);

  bessonov::Circle cir1({ 1, 7 }, 5);
  cir1.move(3, 5);
  std::cout << cir1.getArea() << "\n";

  printRectFrames(&cir1);

  bessonov::Circle cir2({ 8, 4 }, 4);
  cir2.move(4, 3);

  printRectFrames(&cir2);

  return 0;
}
