#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main() {

  Rectangle rec({123,100},5,3);
  Shape* shape1 = &rec;
  shape1->move(10,20);
  std::cout << shape1->getArea() << '\n';

  Circle cir({11,12}, 4);
  Shape* shape2 = &cir;
  rectangle_t frame = shape2->getFrameRect();
  point_t tomove = {10,20};
  shape2->move(tomove);
  std::cout << "Width of rectangle: " <<frame.width << "\nHeight of rectangle: " << frame.height <<'\n';

  return 0;
}
