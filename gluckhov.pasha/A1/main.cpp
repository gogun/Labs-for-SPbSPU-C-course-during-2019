#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void displayFrameRect (const rectangle_t rect);

int main()
{
  Rectangle rect1(5.2, 4, {2.4, -3});
  Shape *ptrShape = &rect1;
  std::cout << "Rectangle: \n";
  ptrShape->displayData();

  rectangle_t frameRect = ptrShape->getFrameRect();
  displayFrameRect(frameRect);
  const double dx = 1.6;
  const double dy = 4;
  ptrShape->move(dx, dy);
  frameRect = ptrShape->getFrameRect();
  std::cout << "\nAfter move: + (" << dx << ';' << dy << "): ("
    << frameRect.pos.x << ';' << frameRect.pos.y << ')';

  Circle circ1(4, {3.2, 2.4});
  ptrShape = &circ1;
  std::cout << "\n\nCircle: " << std::endl;
  ptrShape->displayData();

  frameRect = ptrShape->getFrameRect();
  displayFrameRect(frameRect);
  const point_t position = {4.2, 3};
  ptrShape->move(position);
  frameRect = ptrShape->getFrameRect();
  std::cout << "\nAfter move: to (" << position.x << ';' << position.y << "): ("
    << frameRect.pos.x << ';' << frameRect.pos.y << ')';

  std::cout << std::endl;
  return 0;
}

void displayFrameRect (const rectangle_t rect)
{
  std::cout << "\nRectangle Frame:"
    << "\nWidth: " << rect.width << "\tHeight: " << rect.height
     << "\nPosition: (" << rect.pos.x << ';' << rect.pos.y << ')';
}
