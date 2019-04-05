#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printRect (Shape &Shape)
{
  rectangle_t rectangle = Shape.getFrameRect();
  std::cout << rectnagle.width << " " << rectangle.height;
  std::cout << " " << "(" << rectangle.pos.x << "," <<rectangle.pos.y << ")" << std::endl;
}

int main ()
{
  std::cout << "Rectangle" << std::endl;
  Rectangle rectangle (6,9,{3,4});
  printRect (rectangle);
  double s = rectangle.getArea();
  std::cout << s << std::endl;
  point_t point = {2,1};
  rect.move(point);
  printRect (rectangle);
  rect.move(2,8);
  printRect (rectangle);

  std::cout << "Circle" << std::endl;
  Circle circle ({5,5},4);
  printRect (circle);
  s = circle.getArea();
  std::cout << s << std::endl;
  circle.move({1,1});
  printRect (circle);
  circle.move(2,8);
  printRect (circle);
  return 0;
};
