#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfoAboutShape(const Shape *shape)
{
  assert(shape != nullptr);
  const double area = shape->getArea();
  const rectangle_t frameRect = shape->getFrameRect();
  std::cout << "Shape area is " << area;
  std::cout << "\nShape frame rectangle width and height:";
  std::cout << "\nWidth: " << frameRect.width;
  std::cout << "\nHeight: " << frameRect.height;
  std::cout << "\nPosition of rectangle: x = " << frameRect.pos.x << "\ty = " << frameRect.pos.y << "\n\n";
}

int main()
{
  Circle circle({15.5, 5.3}, 3);
  printInfoAboutShape(&circle);
  circle.move({3.5, 14.4});
  printInfoAboutShape(&circle);
  circle.move(5.2, -4.3);
  printInfoAboutShape(&circle);

  Rectangle rectangle({14.3, 15.2}, 5, 4);
  printInfoAboutShape(&rectangle);
  rectangle.move({5.4, 3.3});
  printInfoAboutShape(&rectangle);
  rectangle.move(3.6, 7.7);
  printInfoAboutShape(&rectangle);

  return 0;
}

