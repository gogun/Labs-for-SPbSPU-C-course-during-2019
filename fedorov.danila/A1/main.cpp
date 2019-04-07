#include <iostream>
#include <cassert>

#include "circle.hpp"
#include "rectangle.hpp"

void workWithFigure(Shape* figure);

int main()
{
  std::cout << "rectangle:" << std::endl;
  Rectangle rectangle({1.5, 2.5}, 5.5, 4.5);
  workWithFigure(&rectangle);

  std::cout << "circle:" << std::endl;
  Circle circle({3.4, 5.3}, 2.0);
  workWithFigure(&circle);

  return 0;
}

void workWithFigure(Shape* figure)
{
  assert(figure != nullptr);

  figure->printInfo();

  figure->move(2.1, -1.2);
  std::cout << "\tmoved figure for  +2.1, -1.2" << std::endl;
  figure->printInfo();

  figure->move({1.0, 2.0});
  std::cout << "\tmoved figure to   (1;2)" << std::endl;
  figure->printInfo();
}
