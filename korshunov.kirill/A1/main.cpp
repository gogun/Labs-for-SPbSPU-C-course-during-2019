#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

int main()
{
  Rectangle rectangle({-5, 32}, 2, 9);
  rectangle.move(5,7);

  Circle circle({10,5}, 13);
  circle.move({31,13});

  Shape * shapes[2] = {&rectangle, &circle,};

  int i = 0;
  for (Shape * shape : shapes)
  {
    rectangle_t shape_for_test = shape->getFrameRect();

    std::cout << "XY:(" << shape_for_test.pos.x << ";" << shape_for_test.pos.y
        << ")\n" << "S = " << shape->getArea() << "\n\n";

    i++;
  }

  return 0;
}
