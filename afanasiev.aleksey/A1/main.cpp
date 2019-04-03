#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void viewInfo(const Shape &figure)
{
  rectangle_t frameRect = figure.getFrameRect();
  std::cout << "Coordinates of position: (";
  std::cout << frameRect.position.x << ", ";
  std::cout << frameRect.position.y << ")" << std::endl;
  std::cout << "Width: " << frameRect.width << std::endl;
  std::cout << "Height: " << frameRect.height << std::endl;
}

void viewArea(const Shape &figure)
{
  std::cout << "Area is " << figure.getArea() << std::endl;
}

int main()
{
  point_t pos = {15, 20};

  Rectangle rectangle(pos, 50, 60);
  Circle circle(pos, 10);

  std::cout << "--RECTANGLE--" << std::endl;
  viewInfo(rectangle);
  viewArea(rectangle);
  std::cout << "--CIRCLE--" << std::endl;
  viewInfo(circle);
  viewArea(circle);

  std::cout << "--NEW_RECTANGLE--" << std::endl;
  rectangle.move(15, 20);
  viewInfo(rectangle);

  point_t nextPos = {40, 50};

  std::cout << "--NEW_CIRCLE--" << std::endl;
  circle.move(nextPos);
  viewInfo(circle);

  return 0;
}