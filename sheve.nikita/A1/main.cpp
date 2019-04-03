#include <iostream>
#include "shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

void printParams(const Shape &s)
{
  rectangle_t outFrRect = s.getFrameRect();
  std::cout << "Its area is " << s.getArea() << std::endl;
  std::cout << "Frame centre position is point (" << outFrRect.pos.x << ";" << outFrRect.pos.y << ")."<< std::endl;
  std::cout << "Its width is " << outFrRect.width << " and height is " << outFrRect.height << std::endl<< std::endl;
}

int main()
{
  std::cout << "Creating Rectangle x=20, y=10, l=15, h=50" << std::endl;
  Rectangle rect ({20,10},15,50);
  Shape *rectp = &rect;
  printParams(rect);
  std::cout << "Moving rectangle to point x=-27, y=52" << std::endl;
  rectp -> move ({-27,52});
  printParams(rect);
  std::cout << "Moving rectangle by dx=10, dy=-30" << std::endl;
  rectp -> move (10,-30);
  printParams(rect);

  std::cout << "Creating Circle x=20, y=30, r=13" << std::endl;
  Circle circ ({20,30},13);
  Shape *circp = &circ;
  printParams(circ);
  std::cout << "Moving circle to point x=32, y=-6" << std::endl;
  circp->move({ 32, -6 });
  printParams(circ);
  std::cout << "Moving circle by dx=-12, dy=9" << std::endl;
  circp -> move (-12,9);
  printParams(circ);

  return 0;
}
