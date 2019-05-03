#include <cassert>
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void demo(zakharova::Shape* figure)
{
  assert(figure != nullptr);
  figure->getInfo();
  figure->move(10, 15);
  std:: cout << "* * * Move 10 by Ox, 15 by Oy * * *" << std::endl;
  figure->getInfo();
  figure->move({ 0,0 });
  std::cout << "* * * Move to (0,0) * * *" << std::endl;
  figure->getInfo();
  figure->scale(2);
  std::cout << "* * * Scale 2 * * *" << std::endl;
  figure->getInfo();
  std::cout << "* * *" << std::endl;
}

int main()
{
  zakharova::Rectangle rectangle(15, 10, { 5,5 });
  demo(&rectangle);
  zakharova::Circle circle(5, { 5,5 });
  demo(&circle);

  return 0;
}
