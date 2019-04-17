#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  uzhegov::Rectangle rec{{0, 0}, 10, 20};
  uzhegov::Shape *shape_r = &rec;
  uzhegov::Circle circle{{1, 1}, 2};
  uzhegov::Shape *shape_c = &circle;

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

  shape_r->scale(2.0);
  std::cout << "PARAMETERS OF THE RECTANGLE AFTER TWOFOLD INCREASE:\n";
  shape_r->printParams();
  shape_c->scale(3.0);
  std::cout << "PARAMETERS OF THE CIRCLE AFTER THREEFOLD INCREASE:\n";
  shape_c->printParams();

  return 0;
}
