#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printArea(const Shape& sh)
{
  std::cout << "Area - " << sh.getArea() << std::endl;
}

void printFrameRect(const Shape& sh)
{
  std::cout << "Frame rectangle width - " << sh.getFrameRect().width << std::endl;
  std::cout << "Frame rectangle height - " << sh.getFrameRect().height << std::endl;
}

void printPosition(const Shape& sh)
{
  std::cout << "Position - " << sh.getFrameRect().pos.x << ',' << sh.getFrameRect().pos.y << std::endl;
}

int main()
{
  point_t centerPoint{0, 0};
  
  Rectangle rect(centerPoint, 2, 4);
  std::cout << "RECTANGLE: " << std::endl;
  printArea(rect);
  printFrameRect(rect);
  printPosition(rect);
  
  std::cout << '\n';
  
  centerPoint = {2, 2};
  rect.move(centerPoint);
  std::cout << "Moved rectangle to (2, 2)" << std::endl;
  printPosition(rect);
  
  rect.move(1, 1);
  std::cout << "Moved rectangle by (1, 1)" << std::endl;
  printPosition(rect);
  
  std::cout << '\n';
  
  Circle cir(centerPoint, 3);
  std::cout << "CIRCLE: " << std::endl;
  printArea(cir);
  printFrameRect(cir);
  printPosition(cir);
  
  std::cout << '\n';
  
  centerPoint = {4, 5};
  cir.move(centerPoint);
  std::cout << "Moved circle to (4, 5)" << std::endl;
  printPosition(cir);
  
  cir.move(0, 1);
  std::cout << "Moved circle by (0, 1)" << std::endl;
  printPosition(cir);
  
  std::cout << '\n';
}
