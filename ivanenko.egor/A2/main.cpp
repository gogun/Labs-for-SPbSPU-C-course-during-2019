#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printArea(const ivanenko::Shape &shape)
{
  std::cout << "Area: " << shape.getArea() << std::endl;
};

void printFrameRectangle(const ivanenko::Shape &shape)
{
  ivanenko::rectangle_t frameRectangle = shape.getFrameRect();
  std::cout << "Width: " << frameRectangle.width << std::endl;
  std::cout << "Height: " << frameRectangle.height << std::endl;
  std::cout << "Center: " << "(" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")";
  std::cout << std::endl;
}

int main()
{
  ivanenko::point_t pointCenter{10,10};
  ivanenko::Rectangle rectangle{5, 5, pointCenter};
  ivanenko::Circle circle(pointCenter, 2);

  printArea(rectangle);
  printFrameRectangle(rectangle);
  rectangle.move(-2,-2);
  printArea(rectangle);
  printFrameRectangle(rectangle);
  rectangle.scale(2.5);
  printArea(rectangle);
  printFrameRectangle(rectangle);

  std::cout << std::endl;

  printArea(circle);
  printFrameRectangle(circle);
  circle.move(3,3);
  printArea(circle);
  printFrameRectangle(circle);
  circle.scale(3.0);
  printArea(circle);
  printFrameRectangle(circle);

  std::cout << std::endl;

  return 0;
}

