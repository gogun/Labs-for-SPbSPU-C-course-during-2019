#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"



int main()
{
  Circle myCircle({5.0, 4.0}, 6.0);
  Shape* myShape = &myCircle;
  myShape->writeParameters();
  myShape->move({7.0, -7.0});
  myShape->writeParameters();
  myShape->move(5.0, 6.0);
  myShape->writeParameters();

  Rectangle myRectangle({{9.0, 10.0}, 5.0, 4.0});
  myShape = &myRectangle;
  myShape->writeParameters();
  myShape->move({7.0, -7.0});
  myShape->writeParameters();
  myShape->move(5.0, 6.0);
  myShape->writeParameters();

  Triangle myTriangle({9.0, 10.0}, 8.0, 4.0, 6.0);
  myShape = &myTriangle;
  myShape->writeParameters();
  myShape->move({7.0, -7.0});
  myShape->writeParameters();
  myShape->move(5.0, 6.0);
  myShape->writeParameters();

  return 0;
}
