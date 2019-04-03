#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printArea(const Shape &Shape_)
{
  std::cout << "area = " << Shape_.getArea() << std::endl;
  std::cout << std::endl;
}

void printFrameRect(const Shape &Shape_)
{
  rectangle_t Rect_ = Shape_.getFrameRect();
  std::cout << "frame rectangle:" << std::endl;
  std::cout << "  width = " << Rect_.width;
  std::cout << "  height = " << Rect_.height;
  point_t point = Rect_.pos;
  std::cout << "  x = " << point.x;
  std::cout << "  y = " << point.y;
  std::cout << std::endl;
}

void printRectangleParameters(const Rectangle &Rect_)
{
  point_t point = Rect_.getPos();
  std::cout << "rectangle: x=" << point.x << ", y=" << point.y << ", width="
      << Rect_.getWidth() << ", height=" << Rect_.getHeight() << std::endl << std::endl;
}

void printCircleParameters(const Circle &Circ_)
{
  point_t point = Circ_.getPos();
  std::cout << "circle: x=" << point.x << ", y=" << point.y << ", rad="
      << Circ_.getRadius() << std::endl << std::endl;
}


int main()
{
  std::cout << "----------Rectangles----------" << std::endl;
  std::cout << "creating rectangle x=-1, y=3, w=2, h=4" << std::endl;
  Rectangle Rect1({ -1, 3 }, 2, 4);
  printRectangleParameters(Rect1);

  std::cout << "creating rectangle (2nd constructor)" << std::endl;
  Rectangle Rect2(-1, 3, 2, 4);
  printRectangleParameters(Rect2);

  printArea(Rect2);
  printFrameRect(Rect2);
  std::cout << "moving rectangle on dx = 1, dy = -2" << std::endl;
  Rect2.move(1, -2);
  printRectangleParameters(Rect2);
  
  std::cout << "moving rectangle to x = 4, y = 5" << std::endl;
  Rect2.move({4, 5});
  printRectangleParameters(Rect2);

  std::cout << "-----------Circles------------" << std::endl;
  std::cout << "creating circle x=-1, y=3, r=4" << std::endl;
  Circle Circ1({ -1, 3 }, 4);
  printCircleParameters(Circ1);

  std::cout << "creating circle (2nd constructor)" << std::endl;
  Circle Circ2(-1, 3, 4);
  printCircleParameters(Circ2);

  printArea(Circ2);
  printFrameRect(Circ2);
  std::cout << "moving circle on dx = 1, dy = -2" << std::endl;
  Circ2.move(1, -2);
  printCircleParameters(Circ2);

  std::cout << "moving circle to x = 4, y = 5" << std::endl;
  Circ2.move({ 4, 5 });
  printCircleParameters(Circ2);

  return 0;
}
