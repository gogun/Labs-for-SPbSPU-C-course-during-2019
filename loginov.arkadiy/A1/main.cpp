#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameRect(const Shape &shape) {
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Width = " << frameRect.width << "  ";
  std::cout << "Height = " << frameRect.height << "  ";
  std::cout << "Point = [ " << frameRect.pos.x << ", " << frameRect.pos.y << " ]";
  std::cout << std::endl;
}

void printArea(const Shape &shape) {
  std::cout << "Area = " << shape.getArea() << std::endl;
}

void printPoint(const Shape &shape) {
  std::cout << "Center = [ " << shape.getFrameRect().pos.x << ", " << shape.getFrameRect().pos.y << " ]";
}

int main() {
  point_t pointBegin = {4.5, 3.5};
  Rectangle rect(pointBegin, 1.0, 1.0);
  Circle circle(pointBegin, 7.0);
  point_t pointNew = {10.0, 10.0};

  std::cout << "Rectangle" << std::endl;
  printFrameRect(rect);
  printArea(rect);
  rect.move(pointNew);
  printPoint(rect);
  std::cout << std::endl << std::endl;

  std::cout << "Circle" << std::endl;
  printFrameRect(circle);
  printArea(circle);
  circle.move(2.1, 2.5);
  printPoint(circle);
  std::cout << std::endl;

  return 0;
}
