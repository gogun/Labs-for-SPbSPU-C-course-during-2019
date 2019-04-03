#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

void showFrame(const rectangle_t frame);

int main()
{

  /*test on example Rectangle:*/
  Rectangle rect1(7.2, 5.7, {5, -2.4});
  Shape * r1 = & rect1;

  std::cout << "Rectangle: ";
  r1->displayData();
  std::cout << "\nArea: " << r1->getArea() << std::endl;

  rectangle_t frameRect = r1->getFrameRect();
  showFrame(frameRect);
  r1->move(2.5, -4.1);
  std::cout << "\n==============================After move -> +2.5, -4.1==============================" << std::endl;
  r1->displayData();

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
