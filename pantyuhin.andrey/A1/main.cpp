#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printArea(const Shape &S)
{
  std::cout << "area = " << S.getArea() << std::endl;
  std::cout << std::endl;
}

void printFrameRect(const Shape &S)
{
  rectangle_t R = S.getFrameRect();
  std::cout << "frame rectangle:" <<std::endl;
  std::cout << "  widh = " << R.widh;
  std::cout << "  height = " << R.height;
  point_t point = R.pos;
  std::cout << "  x = " << point.x;
  std::cout << "  y = " << point.y;
  std::cout << std::endl;
}

void printRectangleParameters(const Rectangle &R)
{
  point_t point = R.getPos();
  std::cout << "rectangle: x=" << point.x << ", y=" << point.y << ", widh=" <<
    R.getWidh() << ", height=" << R.getHeight() << std::endl << std::endl;
}

void printCircleParameters(const Circle &C)
{
  point_t point = C.getPos();
  std::cout << "circle: x=" << point.x << ", y=" << point.y << ", rad=" <<
     C.getRadius() << std::endl << std::endl;
}



int main()
{
  std::cout << "----------Rectangles----------" << std::endl;
  std::cout << "creating rectangle x=-1, y=3, w=2, h=4" << std::endl;
  Rectangle R1({ -1, 3 }, 2, 4);
  printRectangleParameters(R1);

  std::cout << "creating rectangle (2nd constructor)" << std::endl;
  Rectangle R2(-1, 3, 2, 4);
  printRectangleParameters(R2);

  printArea(R2);
  printFrameRect(R2);
  std::cout << "moving rectangle on dx = 1, dy = -2" << std::endl;
  R2.move(1, -2);
  printRectangleParameters(R2);
  
  std::cout << "moving rectangle to x = 4, y = 5" << std::endl;
  R2.move({4, 5});
  printRectangleParameters(R2);

  std::cout << "-----------Circles------------" << std::endl;
  std::cout << "creating circle x=-1, y=3, r=4" << std::endl;
  Circle C1({ -1, 3 }, 4);
  printCircleParameters(C1);

  std::cout << "creating circle (2nd constructor)" << std::endl;
  Circle C2(-1, 3, 4);
  printCircleParameters(C2);

  printArea(C2);
  printFrameRect(C2);
  std::cout << "moving circle on dx = 1, dy = -2" << std::endl;
  C2.move(1, -2);
  printCircleParameters(C2);

  std::cout << "moving circle to x = 4, y = 5" << std::endl;
  C2.move({ 4, 5 });
  printCircleParameters(C2);

  return 0;
}