#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectangle({-5, 32}, 2, 7);
  rectangle.move(3,7);
  rectangle_t rect_test = rectangle.getFrameRect();
  std::cout << "before move" << "-5" << ";" << "32" << "\n"
      << rect_test.center.x << ";" << rect_test.center.y << "\n"
      << "width=" << rect_test.width << " " << "height=" << rect_test.height << "\n"
      << "S=" << rectangle.getArea() << "\n" << "\n";

  Circle circle({10,5}, 13);
  rectangle_t circle_test = circle.getFrameRect();
  std::cout << circle_test.center.x << ";" << circle_test.center.y << "\n"
        << "radius=" << circle_test.width/2 << "\n"
        << "S=" << circle.getArea() << "\n" << "\n";

  return 0;
}
