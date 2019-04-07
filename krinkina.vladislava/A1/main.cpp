#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"


int main()
{
  Circle circle{ {6, 5}, 13 };
  Shape *shape_circle = &circle;

  std::cout << "THE PARAMETERS OF THE CIRCLE\n";
  shape_circle->printInfo();

  shape_circle->move(0, 1);
  std::cout << "the parameters of the circle after move dx = 0, dy = 1 :\n";
  shape_circle->printInfo();

  shape_circle->move({ -3, -2 });
  std::cout << "the parameters of the circle after move centre to the point (-3,2) :\n";
  shape_circle->printInfo();
  std::cout << '\n';

  Rectangle rect{ {1, 5}, 15, 10 };
  Shape *shape_rectangle = &rect;

  std::cout << "THE PARAMETERS OF THE RACTANGLE \n";
  shape_rectangle->printInfo();

  shape_rectangle->move(-1, -5);
  std::cout << "the parameters of the rectangle after move dx = -1, dy = -5:\n";
  shape_rectangle->printInfo();

  shape_rectangle->move({ 3, 1 });
  std::cout << "the parameters of the rectangle after move centre to the point (3,1) :\n";
  shape_rectangle->printInfo();

  return 0;
}
