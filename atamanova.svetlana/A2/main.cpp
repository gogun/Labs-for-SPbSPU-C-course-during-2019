#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printFrameRect(const atamanova::Shape& shape)
{
  atamanova::rectangle_t frameRect = shape.getFrameRect();
  std::cout << frameRect.pos.x << " "
      << frameRect.pos.y << " "
      << frameRect.width << " "
      << frameRect.height << std::endl;
}

int main()
{
  atamanova::Circle c1({4.0, 5.0}, 6.0);
  c1.move(2.0, 2.0);
  std::cout << c1.getArea() << std::endl;

  atamanova::Circle c2({5, 6}, 7);
  c2.move({3.0, 3.0});

  atamanova::Rectangle r1({1.0, 2.0}, 4.0, 5.0);
  r1.move({5.0, 5.0});
  std::cout << r1.getArea() << std::endl;

  atamanova::Rectangle r2({2.0, 3.0}, 5.0, 6.0);
  r2.move(2.0, 2.0);

  printFrameRect(c2);
  printFrameRect(r2);

  c2.scale(2.0);
  r2.scale(3.0);

  printFrameRect(c2);
  printFrameRect(r2);

  return 0;
}
