#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle demCircle1{point_t{2, 3}, 4};
  Circle demCircle2{3, 6, 9};
  Rectangle demRect1{point_t{7, 2}, 5, 4};
  Rectangle demRect2{7, 7, 4, 10};

  Shape* pFigures[] = {&demCircle1, &demCircle2, &demRect1, &demRect2};
  int size = sizeof(pFigures) / sizeof(Shape);
  for(int i = 0; i < size; i++) {
    pFigures[i]->print();
  }

  std::cout << "\tMoving all figures: x + 5, y + 4: \n";
  for(int i = 0; i < size; i++) {
    pFigures[i]->move(5, 4);
    pFigures[i]->print();
  }

  std::cout << "\tMoving all figures to the points with coordinates (1;1):\n";
  for(int i = 0; i < size; i++) {
    pFigures[i]->move(point_t{1, 1});
    pFigures[i]->print();
  }
  return 0;
}
