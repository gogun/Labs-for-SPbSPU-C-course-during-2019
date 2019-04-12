#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printArea(const Shape &Shape_)
{
  std::cout << "area = " << Shape_.getArea() << std::endl;
  std::cout << std::endl;
}

void printFrameRect(const Shape &Shape_)
{
  rectangle_t Rect_ = Shape_.getFrameRect();
  std::cout << "frame rectangle:" << std::endl;
  std::cout << "width = " << Rect_.width;
  std::cout << "  height = " << Rect_.height;
  point_t point = Rect_.pos;
  std::cout << "  x = " << point.x;
  std::cout << "  y = " << point.y;
  std::cout << std::endl << std::endl;
}


int main()
{
  std::cout << "----------Rectangles----------" << std::endl;
  std::cout << "creating rectangle x = -1, y = 3, w = 2, h = 4" << std::endl;
  Rectangle Rect1({-1, 3}, 2, 4);
  Rect1.printParameters();

  std::cout << "creating rectangle (2nd constructor)" << std::endl;
  Rectangle Rect2(-1, 3, 2, 4);
  Rect2.printParameters();

  printArea(Rect2);
  printFrameRect(Rect2);
  std::cout << "moving rectangle on dx = 1, dy = -2" << std::endl;
  Rect2.move(1, -2);
  Rect2.printParameters();
  
  std::cout << "moving rectangle to x = 4, y = 5" << std::endl;
  Rect2.move({4, 5});
  Rect2.printParameters();

  std::cout << "-----------Circles------------" << std::endl;
  std::cout << "creating circle x = -1, y = 3, r = 4" << std::endl;
  Circle Circ1({-1, 3}, 4);
  Circ1.printParameters();

  std::cout << "creating circle (2nd constructor)" << std::endl;
  Circle Circ2(-1, 3, 4);
  Circ2.printParameters();

  printArea(Circ2);
  printFrameRect(Circ2);
  std::cout << "moving circle on dx = 1, dy = -2" << std::endl;
  Circ2.move(1, -2);
  Circ2.printParameters();

  std::cout << "moving circle to x = 4, y = 5" << std::endl;
  Circ2.move({4, 5});
  Circ2.printParameters();


  std::cout << "----------Triangles-----------" << std::endl;
  std::cout << "creating triangle (1; 3), (-4, 2), (-1, -6) with different constructors" << std::endl;

  std::cout << "1st constructor" << std::endl;
  Triangle Triang1({1, 3}, {-4, 2}, {-1, -6});
  Triang1.printParameters();

  std::cout << "2rd constructor" << std::endl;
  Triangle Triang2(1, 3, -4, 2, -1, -6);
  Triang2.printParameters();

  printArea(Triang2);
  printFrameRect(Triang2);
  std::cout << "moving triangle on dx = 1, dy = -2" << std::endl;
  Triang2.move(1, -2);
  Triang2.printParameters();

  std::cout << "moving triangle to x = 4, y = 5" << std::endl;
  Triang2.move({4, 5});
  Triang2.printParameters();

  return 0;
}
