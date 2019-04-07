#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "Rectangle" << std::endl << std::endl;
  Rectangle rect({ 1,1 }, 2, 3);
  Shape *rectPointer = &rect;
  rectPointer->showResults();
  std::cout << "Area of rectangle is " << rectPointer->getArea() << std::endl;
  std::cout << std::endl << "Moving for 2 by x and 3 by y: " << std::endl;
  rectPointer->move(2, 3);
  rectPointer->showResults();
  std::cout << std::endl << "Moving to the (0;-1) " << std::endl;
  rectPointer->move({ 0,-1 });
  rectPointer->showResults();
  std::cout << std::endl  << "Circle" << std::endl << std::endl;
  Circle circ({ 1,1 }, 5);
  Shape *circlePointer = &circ;
  circlePointer->showResults();
  std::cout << "Area of circle is " << circlePointer->getArea() << std::endl << std::endl;
  std::cout << "Moving for 3 by x and 4 by y: " << std::endl;
  circlePointer->move(3, 4);
  circlePointer->showResults();
  std::cout << std::endl << "Moving to the (-1;0) " << std::endl;
  circlePointer->move({ -1,0 });
  circlePointer->showResults();

  return 0;
}
