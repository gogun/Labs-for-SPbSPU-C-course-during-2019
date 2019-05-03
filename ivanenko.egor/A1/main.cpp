#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printArea(const Shape &shape)
{
  std::cout << "area: " << shape.getArea() << std::endl;
};

void printFrameRectangle(const Shape &shape)
{
  rectangle_t frameRectangle = shape.getFrameRect();
  std::cout << "Width: " << frameRectangle.width << std::endl;
  std::cout << "Height: " << frameRectangle.height << std::endl;
  std::cout << "Center: " << "(" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")";
  std::cout << std::endl;
}

int main()
{
  point_t pointCenter{10,10};
  Rectangle rectangle{5, 5, pointCenter};
  Circle circle(pointCenter, 2);

  printArea(rectangle);
  printFrameRectangle(rectangle);
  rectangle.move(-2,-2);
  printFrameRectangle(rectangle);
  std::cout << std::endl;

  printArea(circle);
  printFrameRectangle(circle);
  circle.move(3,3);
  printFrameRectangle(rectangle);
  std::cout << std::endl;

  return 0;
}
