#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void displayFrameRect (rectangle_t);

int main()
{
  // Rectangle TEST
  Rectangle rec1(5.2, 4, {2.4, -3});
  Shape *ptrRec = &rec1;
  std::cout << "Rectangle: \n";
  ptrRec->displayData();

  rectangle_t frameRect = ptrRec->getFrameRect();
  displayFrameRect(frameRect);
  ptrRec->move(1.6, 4);
  frameRect = ptrRec->getFrameRect();
  std::cout << "\nAfter move: + (1.6, 4): (" << frameRect.pos.x << ';' << frameRect.pos.y << ')';

  //END RECTANGLE TEST
  // CIRCLE TEST
  Circle circ1(4, {3.2, 2.4});
  Shape *ptrCir = &circ1;
  std::cout << "\n\nCircle: " << std::endl;
  ptrCir->displayData();

  frameRect = ptrCir->getFrameRect();
  displayFrameRect(frameRect);
  point_t position = {4.2, 3};
  ptrCir->move(position);
  frameRect = ptrCir->getFrameRect();
  std::cout << "\nAfter move: to (4.2, 3): (" << frameRect.pos.x << ';' << frameRect.pos.y << ')';


  std::cout << std::endl;
  return 0;
}

void displayFrameRect (rectangle_t rect)
{

  std::cout << "\nRectangle Frame:"
    << "\nWidth: " << rect.width << "\tHeight: " << rect.height
     << "\nPosition: (" << rect.pos.x << ';' << rect.pos.y << ')';
}
