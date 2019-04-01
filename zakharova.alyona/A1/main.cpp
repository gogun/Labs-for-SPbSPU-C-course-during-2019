#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void demo(Shape* figure)
{
  figure->getInfo();
  figure->move(10, 15);
  figure->getInfo();
  figure->move({ 0,0 });
  figure->getInfo();
}

int main()
{
  Rectangle rect(15, 10, { 5,5 });
  Shape * figure1 = &rect;
  demo(figure1);
  Circle circ(5, { 5,5 });
  Shape * figure2 = &circ;
  demo(figure2);
  return 0;
}
