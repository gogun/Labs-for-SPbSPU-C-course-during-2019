#include <iostream>
#include <cassert>

#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void workWithFigure(Shape* figure);

int main()
{
  Rectangle rect({ 1.5, 2.5 }, 5.5, 4.5);
  std::cout << "rectangle:" << std::endl;
  workWithFigure(&rect);


  Circle circ({ 3.4, 5.3 }, 2.0);
  std::cout << "circle:" << std::endl;
  workWithFigure(&circ);

  return 0;
}

void workWithFigure(Shape* figure)
{
  assert(shape != nullptr)
  
  figure->printInfo();

  figure->move(2.1, -1.2);
  std::cout << "\tmoved figure for  +2.1, -1.2" << std::endl;
  figure->printInfo();

  figure->move({ 1.0, 2.0 });
  std::cout << "\tmoved figure to   (1;2)" << std::endl;
  figure->printInfo();
}
