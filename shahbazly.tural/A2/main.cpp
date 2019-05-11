#include "rectangle.hpp"
#include "circle.hpp"

#include <iostream>

int main()
{
  // Создание объекта типа Rectangle с центром в точке (6.0, 9.0) и шириной - 20, высотой - 30
  shahbazly::Rectangle rectangle({6.0, 9.0}, 20.0, 30.0);

  // Создание объекта типа Circle с радиусом 3 и центром в точке (4; 6)
  shahbazly::Circle circle(3.0, {4.0, 6.0});

  shahbazly::Shape * figures[] = {&circle, &rectangle};
  int SIZE = sizeof(figures) / sizeof(shahbazly::Shape);

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

  // Демонстрация функции масштабирования
  std::cout << "-> scale figures by a factor = 4.7\n\n";
  for (int i = 0; i < SIZE; i++)
  {
    figures[i]->scale(4.7);
    figures[i]->showParameters();
  }

  return 0;
}
