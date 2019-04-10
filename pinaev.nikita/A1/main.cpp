#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "Rectangle" << std::endl << std::endl;
  Rectangle rect({1, 1}, 2, 3);
  Shape *shapePointer = &rect;
  shapePointer->showResults();
  std::cout << "Area of rectangle is " << shapePointer->getArea() << std::endl;
  std::cout << std::endl << "Moving for 2 by x and 3 by y: " << std::endl;
  shapePointer->move(2, 3);
  shapePointer->showResults();
  std::cout << std::endl << "Moving to the (0; -1) " << std::endl;
  shapePointer->move({0, -1});
  shapePointer->showResults();
  std::cout << std::endl  << "Circle" << std::endl << std::endl;
  Circle circ({1, 1}, 5);
  shapePointer = &circ;
  shapePointer->showResults();
  std::cout << "Area of circle is " << shapePointer->getArea() << std::endl << std::endl;
  std::cout << "Moving for 3 by x and 4 by y: " << std::endl;
  shapePointer->move(3, 4);
  shapePointer->showResults();
  std::cout << std::endl << "Moving to the (-1; 0) " << std::endl;
  shapePointer->move({-1, 0});
  shapePointer->showResults();

  return 0;
}
