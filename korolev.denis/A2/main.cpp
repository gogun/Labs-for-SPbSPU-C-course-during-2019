#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

void printInf(const korolev::Shape &shape)
{
  korolev::rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Parameters of frame rectangle: " << std::endl
    << "Center: (" << frameRect.pos.x << ";" << frameRect.pos.y << ")" << std::endl
    << "Width: " << frameRect.width << std::endl
    << "Height: " << frameRect.height << std::endl
    << "Area: " << shape.getArea() << std::endl;
}

void movePoint(korolev::Shape &shape, double x, double y)
{
  printInf(shape);
  shape.move({x, y});
  std::cout << "Parameters of frame rectangle after move: " << std::endl;
  printInf(shape);
}

void moveXY(korolev::Shape &shape, double dx, double dy)
{
  printInf(shape);
  shape.move(dx, dy);
  std::cout << "Parameters of frame rectangle after move: " << std::endl;
  printInf(shape);
}

int main()
{
  korolev::Circle circle({12, 12}, 1.7);
  movePoint(circle, 23, 45);
  moveXY(circle, 45, 12);

  korolev::Rectangle rectangle(12, 34, 23, 56);
  movePoint(rectangle, 67, 78);
  moveXY(rectangle, 17, 34);

  return 0;
}

