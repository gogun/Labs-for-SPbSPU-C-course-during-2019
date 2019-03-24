#include "rectangle.hpp"
#include "circle.hpp"

#include <iostream>

int main()
{
  Rectangle rectangle(4, 2, { 1, 3 });
  Shape * shape = &rectangle;
  std::cout << "FOR RECTANGLE\n";
  shape -> print();
  std::cout << "1) Moving along ОХ " << 4
            << " and OY " << 7 << std::endl;
  shape -> move(4,7);
  shape -> print();
  std::cout << "2) Moving to the point (" << 8
            << "; " << 6 << ")\n";
  shape -> move({ 8, 6 });
  shape -> print();
  std::cout << std::endl;
  
  Circle circle(6, { 2, 3 });
  shape = &circle;
  std::cout << "FOR CIRCLE\n";
  shape -> print();
  std::cout << "1) Moving along ОХ " << 5
            << " and OY " << 9 << std::endl;
  shape -> move(5,9);
  shape -> print();
  std::cout << "2) Moving to the point (" << 9
            << "; " << 3 << ")\n";
  shape -> move({ 9, 3 });
  shape -> print();
  std::cout << std::endl;
  return 0;
}
