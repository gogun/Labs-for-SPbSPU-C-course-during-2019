#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle shape_1({0, 0}, 30, 15);
  Shape *rectangle = &shape_1;
  std::cout << "rectangle created\n\n";

  rectangle -> printData();

  double dx = 15;
  double dy = 30;

  rectangle -> move(dx, dy);
  std::cout << "\nrectangle is moved on (" << dx << ", " << dy << ")\n\n";

  rectangle -> printData();

  Circle shape_2({15, 15}, 15);
  Shape * circle = &shape_2;
  std::cout << "\ncircle created\n\n";

  circle -> printData();

  point_t pos = {0, 0};

  circle -> move(pos);
  std::cout << "\ncircle is moved on (" << pos.x << ", " << pos.y << ")" << "\n\n";

  circle -> printData();

  return 0;
}
