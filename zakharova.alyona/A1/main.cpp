#include <cassert>
#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void demo(Shape* figure)
{
  assert(figure != nullptr);
  figure->getInfo();
  figure->move(10, 15);
  figure->getInfo();
  figure->move({ 0,0 });
  figure->getInfo();
}

int main()
{
  Rectangle rectangle(15, 10, { 5,5 });
  demo(&rectangle);
  Circle circle(5, { 5,5 });
  demo(&circle);
  return 0;
}
