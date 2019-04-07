#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle r1({1.3, 3.7}, 15.0, 15.0);
  std::cout << r1.getArea() << std::endl;

  Rectangle r2({2.0, 1.5}, 2.0, 8.0);
  r2.move(1.5, 2.0);

  Circle c1({0.0, 0.0}, 1.0);
  std::cout << c1.getArea() << std::endl;

  Circle c2({6.0, 6.0}, 6.0);
  c2.move({-6.0, 6.0});

  Shape *circPtr = &c2;
  rectangle_t tmpRect = circPtr->getFrameRect();
  std::cout << tmpRect.pos.x << " " << tmpRect.pos.y << " " << tmpRect.width << " " << tmpRect.height
    << std::endl;

  Shape *rectPtr = &r2;
  tmpRect = rectPtr->getFrameRect();
  std::cout << tmpRect.pos.x << " " << tmpRect.pos.y << " " << tmpRect.width << " " << tmpRect.height
    << std::endl;
  return 0;
}
