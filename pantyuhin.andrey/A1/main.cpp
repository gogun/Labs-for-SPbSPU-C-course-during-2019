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

void shapeTest(Shape &Shape1_, Shape &Shape2_)
{
  Shape1_.printParameters();

  std::cout << "creating same shape (2nd constructor)" << std::endl;
  Shape2_.printParameters();

  printArea(Shape2_);
  printFrameRect(Shape2_);
  std::cout << "moving shape on dx = 1, dy = -2" << std::endl;
  Shape2_.move(1, -2);
  Shape2_.printParameters();

  std::cout << "moving shape to x = 4, y = 5" << std::endl;
  Shape2_.move({4, 5});
  Shape2_.printParameters();
}

int main()
{
  std::cout << "----------Rectangles----------" << std::endl;
  std::cout << "creating shape: x = -1, y = 3, w = 2, h = 4" << std::endl;
  Rectangle Rect1({-1, 3}, 2, 4);
  Rectangle Rect2(-1, 3, 2, 4);

  shapeTest(Rect1, Rect2);

  std::cout << "-----------Circles------------" << std::endl;
  std::cout << "creating shape: x = -1, y = 3, r = 4" << std::endl;
  Circle Circ1({-1, 3}, 4);
  Circle Circ2(-1, 3, 4);

  shapeTest(Circ1, Circ2);

  std::cout << "----------Triangles-----------" << std::endl;
  std::cout << "creating shape: (1; 3), (-4; 2), (-1; -6)" << std::endl;
  Triangle Triang1({1, 3}, {-4, 2}, {-1, -6});
  Triangle Triang2(1, 3, -4, 2, -1, -6);

  shapeTest(Triang1, Triang2);

  return 0;
}
