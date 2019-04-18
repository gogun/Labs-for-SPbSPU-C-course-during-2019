#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  ivleva::Rectangle rectangle({4, 2, {1, 3}});
  ivleva::Shape * shapePtr = &rectangle;
  std::cout << "Rectangle movement\n";
  shapePtr->print();
  std::cout << "1) Moving along " << 3 << " and Oy " << 7 << std::endl;
  shapePtr->move(3, 7);
  shapePtr->print();
  std::cout << "2) Moving to the point (" << 4 << "; " << 3 << ")\n";
  shapePtr->move({4, 3});
  shapePtr->scale(2.0);
  shapePtr->print();
  std::cout << std::endl;
    
  ivleva::Circle circle(6, {2, 3});
  shapePtr = &circle;
  std::cout << "Circle movement\n";
  shapePtr->print();
  std::cout << "1) Moving along  " << 3 << " and Oy " << 6 << std::endl;
  shapePtr->move(3, 6);
  shapePtr->scale(2.0);
  shapePtr->print();
  std::cout << "2) Moving to the point (" << 6 << "; " << 3 << ")\n";
  shapePtr->move({6, 3});
  shapePtr->print();
  return 0;
}
