#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  /*Rectangle*/
  Rectangle rectangle({ 5,10 }, 6, 20);
  Shape *figure = &rectangle;
  figure->getInfo();
  std::cout << "Move rectangle on dx = 3 and dy = 4" << std::endl;
  figure->move(3, 4);
  figure->getInfo();
  std::cout << "Move rectangle to point (5,7)" << std::endl;
  figure->move({ 5, 7 });
  figure->getInfo();
  std::cout << "Rectangle area = " << figure->getArea() << std::endl;
  std::cout << "------------------------------------------" << std::endl;
  /*Circle*/
  Circle circle({ 13,15 }, 5);
  figure = &circle;
  figure->getInfo();
  std::cout << "Move circle on dx = 5 and dy = 10" << std::endl;
  figure->move(5, 10);
  figure->getInfo();
  std::cout << "Move circle to point (1,1)" << std::endl;
  figure->move({ 1, 1 });
  figure->getInfo();
  std::cout << "Circle area = " << figure->getArea() << std::endl;

 system("pause");
  return 0;
}
