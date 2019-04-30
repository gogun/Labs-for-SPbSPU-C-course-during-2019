#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Circle circ1({4.0, 2.2}, 5.0);
  Shape *shapePointer = &circ1;

  std::cout << "Circle\n";
  shapePointer->printInfo();
  std::cout << "S = " << shapePointer->getArea() << "\n";

  rectangle_t temp_rect = shapePointer->getFrameRect();
  std::cout << "Center = " << temp_rect.pos.x << ";" << temp_rect.pos.y
      << " Width = " << temp_rect.width << " Height = " << temp_rect.height << "\n";

  shapePointer->move({2.3, 3.5});
  shapePointer->printInfo();

  Rectangle rect1({3.4, 3.4}, 6.2, 6.2);
  shapePointer = &rect1;

  std::cout << "Rectangle\n";
  shapePointer->printInfo();
  std::cout << "S = " << shapePointer->getArea() << "\n";
  shapePointer->move(2.1, 4.0);
  shapePointer->printInfo();

  Triangle trian1({2.2, 3.3}, {1.8, 3.7}, {5.0, 5.0});
  shapePointer = &trian1;

  std::cout << "Triangle\n";
  shapePointer->printInfo();
  std::cout << "S = " << shapePointer->getArea() << "\n";

  temp_rect = shapePointer->getFrameRect();
  std::cout << "Center = " << temp_rect.pos.x << ";" << temp_rect.pos.y
      << " Width = " << temp_rect.width << " Height = " << temp_rect.height << "\n";

  shapePointer->move(2.1, 4.2);
  shapePointer->printInfo();
  shapePointer->move({6.0, 6.0});
  shapePointer->printInfo();

  return 0;
}
