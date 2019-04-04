#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

void printInf(const Shape &shape)
{
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Center: (" << frameRect.pos.x << ";" << frameRect.pos.y << ")" << std::endl
    << "Width: " << frameRect.width << std::endl
    << "Height: " << frameRect.height << std::endl
    << "Area: " << shape.getArea() << std::endl;
}

void movePoint(Shape &shape, double x, double y)
{
  std::cout << "Parameters of frame rectangle: " << std::endl;
  printInf(shape);
  shape.move({x, y});
  std::cout << "Parameters of frame rectangle after move: " << std::endl;
  printInf(shape);
}

void moveXY(Shape &shape, double dx, double dy)
{
  std::cout << "Parameters of frame rectangle: " << std::endl;
  printInf(shape);
  shape.move(dx, dy);
  std::cout << "Parameters of frame rectangle after move: " << std::endl;
  printInf(shape);
}

int main()
{
  Circle circle({12, 12}, 12);
  movePoint(circle, 23, 45);
  moveXY(circle, 45, 12);

  Rectangle rectangle(12, 34, 23 , 56);
  movePoint(rectangle, 67, 78);
  moveXY(rectangle, 17, 34);

  return 0;
}

