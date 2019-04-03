#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

void showFrame(const rectangle_t frame);

int main()
{
  /*test on example Rectangle:*/
  Rectangle rect1(7.2, 5.7, {5, -2.4});
  Shape * ptrRect = & rect1;

  std::cout << "Rectangle: ";
  ptrRect->displayData();
  std::cout << "\nArea: " << ptrRect->getArea() << std::endl;

  rectangle_t frameRect = ptrRect->getFrameRect();
  showFrame(frameRect);
  ptrRect->move(2.5, -4.1);
  std::cout << "\n==============================After move -> +2.5, -4.1==============================";
  ptrRect->displayData();

  /*test on example Circle:*/
  Circle cirptrCirc(5);
  Shape *ptrCirc = &cirptrCirc;

  std::cout << std::endl << "\nCircle: ";
  ptrCirc->displayData();
  std::cout << "\nArea: " << ptrCirc->getArea() << std::endl;

  frameRect = ptrCirc->getFrameRect();
  showFrame(frameRect);
  point_t position = {-1.8, 2.4};
  ptrCirc->move(position);
  std::cout << "\n==============================After move to (-1.8, 2.4)==============================";
  ptrCirc->displayData();

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
