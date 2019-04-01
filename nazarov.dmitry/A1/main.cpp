#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rect({ 0, 0 }, 20, 10); 
  Circle circle({ 10, 10 }, 10); 
  Shape * shapes[2] = { &rect, &circle };

  rect.move(10, 20); 
  circle.move(5, 6); 

  std::cout << "FIGURES WERE MOVED BY DX AND DY\n\n";
  for (Shape * shape : shapes) {
    shape->printData();
  }

  rect.move({ 4, 5 }); 
  circle.move({ 0, 0 }); 

  std::cout << "FIGURES WERE MOVED BY COORDINATE\n\n";
  for (Shape * shape : shapes) {
    shape->printData();
  }

  return 0;
}
