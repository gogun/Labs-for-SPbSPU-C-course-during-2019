#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle demCircle1{point_t{2, 3}, 4}; //dem - demonstration (of circles and rectangles)
  Circle demCircle2{3, 6, 9};
  Rectangle demRect1{point_t{7, 2}, 5, 4};
  Rectangle demRect2{7, 7, 4, 10};

  Shape* pFigures[] = {&demCircle1, &demCircle2, &demRect1, &demRect2}; //p - pointer (to Figures array)

  for(Shape* element:pFigures) {
    element->print();
  }
  std::cout << "\tMoving all figures: x + 5, y + 4: \n";
  for(Shape* element:pFigures) {
    element->move(5, 4);
    element->print();
  }

  std::cout << "\tMoving all figures to the points with coordinates (1;1):\n";
  for(Shape* element:pFigures) {
    element->move(point_t{1, 1});
    element->print();
  }
  return 0;
}
