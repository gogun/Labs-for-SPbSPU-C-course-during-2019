#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

void viewShape(const Shape *shape);

int main()
{
  /*test on example Rectangle:*/
  Rectangle rect1(7.2, 5.7, {5, -2.4});
  Shape * ptrShape = & rect1;

  std::cout << "Rectangle: ";
  viewShape(ptrShape);

  double dx = 2.5, dy = -4.1;
  ptrShape->move(dx, dy);
  std::cout << "\n============After move: + (" << dx << ';' << dy << ")============";
  ptrShape->displayData();

  std::cout << std::endl;
  /*test on example Circle:*/
  Circle cirptrShape(5);
  ptrShape = &cirptrShape;

  std::cout << "\nCircle: ";
  viewShape(ptrShape);

  point_t position = {-1.8, 2.4};
  ptrShape->move(position);
  std::cout << "\n============After move to (-1.8, 2.4)============";
  ptrShape->displayData();

  std::cout << std::endl;
  return 0;
}

void viewShape(const Shape *shape)
{
  shape->displayData();
  std::cout << "\nArea: " << shape->getArea() << std::endl;
  rectangle_t frameRect = shape->getFrameRect();
  std::cout << "***Frame Rectangle:" << std::endl
    << "Width: " << frameRect.width
      << "\nHeight: " << frameRect.height
        << "\nPosition: (" << frameRect.pos.x << ';' << frameRect.pos.y << ')';
}
