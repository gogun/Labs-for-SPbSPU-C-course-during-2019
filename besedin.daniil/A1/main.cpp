#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameRect(const Shape &shape, const std::string &name)
{
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << name << std::endl;
  std::cout << "Width: " << frameRect.width << "  ";
  std::cout << "Height: " << frameRect.height << "  ";
  std::cout << "Center: ( " << frameRect.pos.x << " , " << frameRect.pos.y << " )";
  std::cout << std::endl;
}

void printArea(const Shape &shape)
{
  std::cout << "Area: " << shape.getArea() << std::endl;
}

void printCenter(const Shape &shape)
{
  std::cout << "Center: ( " << shape.getFrameRect().pos.x << " , " << shape.getFrameRect().pos.y << " )";
}

int main()
{
  point_t pointCenter = {5, 5};
  Rectangle rectangle(3, 3, pointCenter);
  Circle circle(7, pointCenter);
  point_t pointNewCenter = {15, 15};

  printFrameRect(rectangle, "Rectangle");
  printArea(rectangle);
  rectangle.move(3, 3);
  printCenter(rectangle);
  std::cout << std::endl << std::endl;

  printFrameRect(circle, "Circle");
  printArea(circle);
  circle.move(pointNewCenter);
  printCenter(circle);
  std::cout << std::endl;

  return 0;
}
