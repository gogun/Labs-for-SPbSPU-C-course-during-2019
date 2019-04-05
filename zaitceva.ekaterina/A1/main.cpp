#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printRect (Shape &Shape)
{
  rectangle_t rectangle1 = Shape.getFrameRect();
  std::cout << rectangle1.width << " " << rectangle1.height;
  std::cout << " " << "(" << rectangle1.pos.x << "," <<rectangle1.pos.y << ")" << std::endl;
}

int main ()
{
  std::cout << "Rectangle" << std::endl;
  Rectangle rectangle (6,9,{3,4});
  printRect (rectangle);
  std::cout << "Area = " << rectangle.getArea() << std::endl;
  rectangle.move({2,1});
  printRect (rectangle);
  rectangle.move(2,8);
  printRect (rectangle);

  std::cout << "Circle" << std::endl;
  Circle circle ({5,5},4);
  printRect (circle);
  std::cout << "Area = " << circle.getArea() << std::endl;
  circle.move({1,1});
  printRect (circle);
  circle.move(2,8);
  printRect (circle);
  return 0;
};
