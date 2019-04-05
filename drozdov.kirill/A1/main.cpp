#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

void showFrame(const rectangle_t frame);

int main()
{
  /*test on example Rectangle:*/
  Rectangle rect1(7.2, 5.7, {5, -2.4});
  Shape * ptrShape = & rect1;

  std::cout << "Rectangle: ";
  ptrShape->displayData();
  std::cout << "\nArea: " << ptrShape->getArea() << std::endl;

  rectangle_t frameRect = ptrShape->getFrameRect();
  showFrame(frameRect);
  ptrShape->move(2.5, -4.1);
  std::cout << "\n==============================After move -> +2.5, -4.1==============================";
  ptrShape->displayData();

  /*test on example Circle:*/
  Circle cirptrShape(5);
  ptrShape = &cirptrShape;

  std::cout << std::endl << "\nCircle: ";
  ptrShape->displayData();
  std::cout << "\nArea: " << ptrShape->getArea() << std::endl;

  frameRect = ptrShape->getFrameRect();
  showFrame(frameRect);
  point_t position = {-1.8, 2.4};
  ptrShape->move(position);
  std::cout << "\n==============================After move to (-1.8, 2.4)==============================";
  ptrShape->displayData();

  std::cout << std::endl;
  return 0;
}

void showFrame(const rectangle_t frame)
{
  std::cout << "Frame Rectangle:" << std::endl
    << "Width: " << frame.width
    << "\nHeight: " << frame.height
    << "\nPosition: (" << frame.pos.x << ';' << frame.pos.y << ')';
}
