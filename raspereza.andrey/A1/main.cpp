#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{ 
  Circle circ1({4.0,2.2}, 5.0);
  std::cout << "Circle\n";
  circ1.printInfo();
  std::cout << "S=" << circ1.getArea() << "\n";
  
  circ1.move({2.3,3.5});

  Shape *circPointer = &circ1;
  rectangle_t temp_rect = circPointer->getFrameRect();
  std::cout << "Center= " << temp_rect.pos.x << ";" << temp_rect.pos.y
    << " Width= " << temp_rect.width << " Height= " << temp_rect.height << "\n";
  
  Rectangle rect1({3.4,3.4}, 6.2, 6.2);
  std::cout << "Rectangle\n";
  rect1.printInfo();
  std::cout << "S=" << rect1.getArea() << "\n";

  rect1.move(2.1, 4.0);

  Shape *rectPointer = &rect1;
  rectPointer->printInfo();

  return 0;
}
