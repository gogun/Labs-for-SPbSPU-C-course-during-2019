#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameRect(const Shape &shape)
{
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Width = " << frameRect.width << "  ";
  std::cout << "Height = " << frameRect.height << "  ";
  std::cout << "Centre = [ " << frameRect.pos.x << ", " << frameRect.pos.y << " ]" << std::endl;
}

void printArea(const Shape &shape)
{
  std::cout << "Area = " << shape.getArea() << std::endl;
}

void printCentre(const Shape &shape)
{
  std::cout << "Centre = [ " << shape.getFrameRect().pos.x << ", " << shape.getFrameRect().pos.y << " ]";
}

int main()
{
  point_t pointBegin = { 4.5, 3.5 };
  Rectangle rect(pointBegin, 1.0, 1.0);
  Circle circle(pointBegin, 7.0);
  point_t pointNew = { 10.0, 10.0 };

  std::cout << "Rectangle" << std::endl;
  printFrameRect(rect);
  printArea(rect);
  rect.move(pointNew);
  printCentre(rect);
  std::cout << std::endl << std::endl;

  std::cout << "Circle" << std::endl;
  printFrameRect(circle);
  printArea(circle);
  circle.move(2.1, 2.5);
  printCentre(circle);
  std::cout << std::endl;

  return 0;
}
