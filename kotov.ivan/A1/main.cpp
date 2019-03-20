#include <stdio.h>
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

int main()
{
  point_t posRect, posCircle;
  posRect.x = 50;
  posRect.y = 50;
  posCircle.x = 25;
  posCircle.y = 25;
  Rectangle rect(posRect, 10, 10);
  Circle circle(posCircle, 5);
  Shape *a, *b;
  a = &rect;
  b = &circle;
  a -> move(-5, -5);
  b -> move(-5, -5);
  std::cout << "Square of rectangle: " << a -> getArea() << std::endl;
  std::cout << "Square of circle: " << b -> getArea() << std::endl;
  return 0;
}
