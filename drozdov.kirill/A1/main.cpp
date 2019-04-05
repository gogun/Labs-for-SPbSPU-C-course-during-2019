#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

<<<<<<< HEAD
void viewShape(const Shape *shape);
=======
void showFrame(const rectangle_t frame);
>>>>>>> 022b357073f22d6ed6da8cec9140c3bebf0d615c

int main()
{
  /*test on example Rectangle:*/
  Rectangle rect1(7.2, 5.7, {5, -2.4});
<<<<<<< HEAD
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
=======
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
>>>>>>> 022b357073f22d6ed6da8cec9140c3bebf0d615c

  std::cout << std::endl;
  return 0;
}

<<<<<<< HEAD
void viewShape(const Shape *shape)
{
  shape->displayData();
  std::cout << "\nArea: " << shape->getArea() << std::endl;
  rectangle_t frameRect = shape->getFrameRect();
  std::cout << "***Frame Rectangle:" << std::endl
    << "Width: " << frameRect.width
      << "\nHeight: " << frameRect.height
        << "\nPosition: (" << frameRect.pos.x << ';' << frameRect.pos.y << ')';
=======
void showFrame(const rectangle_t frame)
{
  std::cout << "Frame Rectangle:" << std::endl
    << "Width: " << frame.width
    << "\nHeight: " << frame.height
    << "\nPosition: (" << frame.pos.x << ';' << frame.pos.y << ')';
>>>>>>> 022b357073f22d6ed6da8cec9140c3bebf0d615c
}
