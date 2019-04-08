#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectangle({ 3, 3, {1, 1} });
  Shape * shapePtr = &rectangle;
  std::cout << "FOR RECTANGLE\n";
  shapePtr->print();
  std::cout << "1) Moving along 0x " << 7 << " and 0y " << 7 << std::endl;
  shapePtr->move(7, 7);
  shapePtr->print();
  std::cout << "2) Moving to the point (" << 9 << "; " << 9 << ")\n";
  shapePtr->move({ 9, 9 });
  shapePtr->print();
  std::cout << std::endl;

  Circle circle(5, { 3, 3 });
  shapePtr = &circle;
  std::cout << "FOR CIRCLE\n";
  shapePtr->print();
  std::cout << "1) Moving along 0x " << 9 << " and 0y " << 9 << std::endl;
  shapePtr->move(9, 9);
  shapePtr->print();
  std::cout << "2) Moving to the point (" << 8 << "; " << 8 << ")\n";
  shapePtr->move({ 8, 8 });
  shapePtr->print();

  system("pause");

  return 0;
}
