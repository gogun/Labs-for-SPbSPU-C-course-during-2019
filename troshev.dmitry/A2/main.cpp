#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  troshev::Rectangle rectangle({ 5, 25 }, 10, 10);
  std::cout << "RECTANGLE" << std::endl;
  troshev::Shape *figure = &rectangle;
  figure->getInfo();
  std::cout << "Move rectangle on dx = 3 and dy = 3" << std::endl;
  figure->move(3, 3);
  figure->getInfo();
  std::cout << "Move rectangle to point (7, 7)" << std::endl;
  figure->move({ 7, 7 });
  figure->getInfo();
  std::cout << "Area : " << figure->getArea() << std::endl;
  troshev::Circle circle({ 20, 15 }, 6);
  std::cout << "CIRCLE" << std::endl;
  figure = &circle;
  figure->getInfo();
  std::cout << "Move circle on dx = 5 and dy = 6" << std::endl;
  figure->move(5, 6);
  figure->getInfo();
  std::cout << "Move circle to point (10, 10)" << std::endl;
  figure->move({ 10, 10 });
  figure->getInfo();
  std::cout << "Area : " << figure->getArea() << std::endl;

  return 0;
}

