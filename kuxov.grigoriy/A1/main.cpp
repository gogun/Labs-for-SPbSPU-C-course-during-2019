#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  Rectangle rectangle({ 3.0, 3.0, {1.0, 1.0} });
  Shape * shapePtr = &rectangle;
  std::cout << "FOR RECTANGLE\n";
  shapePtr->print();
  std::cout << "1) Moving along 0x " << 7 << " and 0y " << 7 << std::endl;
  shapePtr->move(7.0, 7.0);
  shapePtr->print();
  std::cout << "2) Moving to the point (" << 9 << "; " << 9 << ")\n";
  shapePtr->move({ 9.0, 9.0 });
  shapePtr->print();
  std::cout << std::endl;

  Circle circle(5.0, { 3.0, 3.0 });
  shapePtr = &circle;
  std::cout << "FOR CIRCLE\n";
  shapePtr->print();
  std::cout << "1) Moving along 0x " << 9 << " and 0y " << 9 << std::endl;
  shapePtr->move(9.0, 9.0);
  shapePtr->print();
  std::cout << "2) Moving to the point (" << 8 << "; " << 8 << ")\n";
  shapePtr->move({ 8.0, 8.0 });
  shapePtr->print();

  Triangle triangle({ 2.0, 2.0 }, { 7.0, 7.0 }, { 3.0, 3.0 });
  shapePtr = &triangle;
  std::cout << "\nFOR TRIANGLE\n";
  shapePtr->print();
  std::cout << "\n1) Moving along 0x " << 4 << " and 0y " << 4 << std::endl;
  shapePtr->move(4.0, 4.0);
  shapePtr->print();
  std::cout << "\n2) Moving to the point (" << 5 << ";" << 5 << ")\n";
  point_t nPosTrian = { 5.0, 5.0 };
  shapePtr->move(nPosTrian);
  shapePtr->print();

  return 0;
}
