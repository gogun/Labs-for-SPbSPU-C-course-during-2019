#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rec{{0, 0}, 10, 20}; //прямоугольник с центом в точке (0, 0), шириной 10 и высотой 20
  Shape *shape_r = &rec;
  Circle circle{{1, 1}, 2}; //окружность с центром в точке (1, 1) и радиусом 2
  Shape *shape_c = &circle;

  std::cout << "PARAMETERS OF THE RECTANGLE:\n";
  shape_r->printParams();
  std::cout << "PARAMETERS OF THE CIRCLE:\n";
  shape_c->printParams();

  shape_r->move(2, 5);
  std::cout << "PARAMETERS OF THE RECTANGLE AFTER MOVE dx = 2, dy = 5:\n";
  shape_r->printParams();
  shape_c->move(9, 4);
  std::cout << "PARAMETERS OF THE CIRCLE AFTER MOVE dx = 9, dy = 4:\n";
  shape_c->printParams();

  shape_r->move({-1, -1});
  std::cout << "PARAMETERS OF THE RECTANGLE AFTER MOVE TO (-1, -1):\n";
  shape_r->printParams();
  shape_c->move({-1, -1});
  std::cout << "PARAMETERS OF THE CIRCLE AFTER MOVE TO (-1, 1):\n";
  shape_c->printParams();

  return 0;
}
