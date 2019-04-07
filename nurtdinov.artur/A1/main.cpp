#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfoAboutShape(const Shape *shape)
{
  assert(shape != nullptr);
  const double area = shape->getArea();
  const rectangle_t frameRect = shape->getFrameRect();
  std::cout << "Shape area is " << area << '\n';
  std::cout << "Shape frame rectangle width and height:" << '\n';
  std::cout << "Width = " << frameRect.width << '\n';
  std::cout << "Height = " << frameRect.height << '\n';
  std::cout << "Position of rectangle: x = " << frameRect.pos.x << ", y = " << frameRect.pos.y << "\n\n";
}

int main()
{
  Circle circle({15.5, 5.3}, 3.4);
  printInfoAboutShape(&circle);
  circle.move({3.5, 14.4});
  printInfoAboutShape(&circle);
  circle.move(5.2, 4.3);
  printInfoAboutShape(&circle);

  Rectangle rectangle({14.3, 15.2}, 5.1, 4.3);
  printInfoAboutShape(&rectangle);
  rectangle.move({5.4, 3.3});
  printInfoAboutShape(&rectangle);
  rectangle.move(3.6, 7.7);
  printInfoAboutShape(&rectangle);

  return 0;
}
