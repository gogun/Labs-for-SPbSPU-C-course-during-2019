#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle circle1{point_t{2, 3}, 4};
  Circle circle2{3, 6, 9};
  Rectangle rect1{point_t{7, 2}, 5, 4};
  Rectangle rect2{7, 7, 4, 10};

  Shape* figures[] = {&circle1, &circle2, &rect1, &rect2};

  for(Shape* element:figures) {
    element->print();
  }
  std::cout << "\tMoving all figures: x + 5, y + 4: \n";
  for(Shape* element:figures) {
    element->move(5, 4);
    element->print();
  }

  std::cout << "\tMoving all figures to the points with coordinates (1;1):\n";
  for(Shape* element:figures) {
    element->move(point_t{1, 1});
    element->print();
  }
  return 0;
}
