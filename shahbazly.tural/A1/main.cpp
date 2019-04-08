#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  // Создание объекта типа Rectangle с центром в точке (6.9, 9.6) и шириной - 20, высотой - 30
  Rectangle rectangle({6.0, 9.0}, 20.0, 30.0);

  // Создание объекта типа Circle с радиусом 3 и центром в точке (4;6)
  Circle circle(3.0, {4.0, 6.0});

  Shape * figures[] = {&circle, &rectangle};
  int SIZE = sizeof(figures) / sizeof(Shape);

  for (int i = 0; i < SIZE; i++)
  {
    figures[i]->showParameters();
  }
  
  std::cout << "-> move figures to (6, 9)\n\n";
  for (int i = 0; i < SIZE; i++)
  {
    figures[i]->move(6.0, 9.0);
    figures[i]->showParameters();
  }

  std::cout << "-> shift figures to (77, 7)\n\n";
  for (int i = 0; i < SIZE; i++)
  {
    figures[i]->move({77, 7});
    figures[i]->showParameters();
  }

  return 0;
}
