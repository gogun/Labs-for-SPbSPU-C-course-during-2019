#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main() {
  Rectangle rec({123,100},5,3);
  Shape* w = &rec;
  std::cout << w->getArea() << '\n';
  Circle cir({11,12}, 4);
  Shape* e = &cir;
  std::cout << e->getArea() << '\n';
  return 0;
}
