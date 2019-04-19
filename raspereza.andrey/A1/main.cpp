#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include <iostream>

int main()
{ 
  Circle circ1({4.0, 2.2}, 5.0);
  std::cout << "Circle\n";
  circ1.printInfo();
  std::cout << "S = " << circ1.getArea() << "\n";
  
  circ1.move({2.3, 3.5});

  Shape *circPointer = &circ1;
  rectangle_t temp_rect1 = circPointer->getFrameRect();
  std::cout << "Center = " << temp_rect1.pos.x << ";" << temp_rect1.pos.y
      << " Width = " << temp_rect1.width << " Height = " << temp_rect1.height << "\n";
  
  Rectangle rect1({3.4, 3.4}, 6.2, 6.2);
  std::cout << "Rectangle\n";
  rect1.printInfo();
  std::cout << "S = " << rect1.getArea() << "\n";

  rect1.move(2.1, 4.0);

  Shape *rectPointer = &rect1;
  rectPointer->printInfo();

  Triangle trian1({2.2, 3.3}, {1.8, 3.7}, {5.0, 5.0});
  std::cout << "Triangle\n";
  trian1.printInfo();
  std::cout << "S = " << trian1.getArea() << "\n";
  
  trian1.move(2.1, 4.2);
  trian1.printInfo();
  trian1.move({6.0, 6.0});
  trian1.printInfo();
  
  Shape *trianPointer = &trian1;
  rectangle_t temp_rect2 = trianPointer->getFrameRect();
  std::cout  << " Width = " << temp_rect2.width << " Height = " << temp_rect2.height << "\n";

  return 0;
}
