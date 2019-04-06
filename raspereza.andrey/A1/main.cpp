#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{ 
  Circle circ1({4.0,2.2}, 5.0);
  std::cout << "S=" << circ1.getArea() << std::endl;

  circ1.move({2.3,3.5});

  Shape *circPointer = &circ1;
  rectangle_t temp_rect = circPointer->getFrameRect();
  std::cout << "x=" << temp_rect.pos.x << " y=" << temp_rect.pos.y 
    << " width=" << temp_rect.width << " height=" << temp_rect.height << std::endl;
  
  Rectangle rect1({3.4,3.4}, 6.2, 6.2);
  std::cout <<"S=" << rect1.getArea() << std::endl;

  rect1.move(2.1, 4.0);

  Shape *rectPointer = &rect1;
  temp_rect = rectPointer->getFrameRect();
  std::cout << "x=" << temp_rect.pos.x << " y=" << temp_rect.pos.y 
    << " width=" << temp_rect.width << " height=" << temp_rect.height << std::endl;

  return 0;
}