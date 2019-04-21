#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  blyshchik::Circle circle1{point_t{2, 3.2}, 4};
  blyshchik::Circle circle2{3, 6, 9};
  blyshchik::Rectangle rect1{point_t{7, 2}, 5, 4};
  blyshchik::Rectangle rect2{7, 7, 4, 10};

  blyshchik::Shape* figures[] = {&circle1, &circle2, &rect1, &rect2};

  for (blyshchik::Shape* element:figures) {
    element->print();
  }
  std::cout << "\tMoving all figures: x + 5, y + 4: \n";
  for (blyshchik::Shape* element:figures) {
    element->move(5, 4);
    element->print();
  }

  std::cout << "\tMoving all figures to the points with coordinates (1;1): \n";
  for (blyshchik::Shape* element:figures) {
    element->move(point_t{1, 1});
    element->print();
  }

  const double coefficient = 1.4;
  std::cout << "\tScaling all figures by coefficient " << coefficient << ": \n";
  for (blyshchik::Shape* element:figures) {
    element->scale(coefficient);
    element->print();
  }
  return 0;
}
