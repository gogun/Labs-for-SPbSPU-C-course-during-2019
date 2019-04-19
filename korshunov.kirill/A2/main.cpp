#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

int main()
{
  korshunov::Rectangle rectangle({ -5, 32 }, 2, 9);
  rectangle.move(5, 7);
  rectangle.scale(10);

  korshunov::Circle circle({ 10, 5 }, 13);
  circle.move({ 31, 13 });
  circle.scale(10);

  korshunov::Shape * shapes[] = {&rectangle, &circle,};

  for (const korshunov::Shape * shape : shapes)
  {
    korshunov::rectangle_t shape_for_test = shape->getFrameRect();

    std::cout << "XY:(" << shape_for_test.pos.x << ";" << shape_for_test.pos.y
        << ")\n" << "S = " << shape->getArea() << "\n\n";
  }

  return 0;
}
