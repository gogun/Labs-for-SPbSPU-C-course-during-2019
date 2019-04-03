#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void viewInfo(const Shape &figure)
{
  rectangle_t frameRect = figure.getFrameRect();
  std::cout << "Coordinates of position: (";
  std::cout << frameRect.pos.x << ", ";
  std::cout << frameRect.pos.y << ")" << std::endl;
  std::cout << "Width: " << frameRect.width << std::endl;
  std::cout << "Height: " << frameRect.height << std::endl;
}

void viewArea(const Shape &figure)
{
  std::cout << "Area is " << figure.getArea() << std::endl;
}

int main()
{
  point_t point = {15, 20};

  Rectangle rectangle(point, 50, 60);
  Circle circle(point, 10);

  std::cout << "--RECTANGLE--" << std::endl;
  viewInfo(rectangle);
  viewArea(rectangle);
  std::cout << "--CIRCLE--" << std::endl;
  viewInfo(circle);
  viewArea(circle);

  std::cout << "--RECTANGLE--" << std::endl;
  rectangle.move(15, 20);
  viewInfo(rectangle);

  point_t newPoint = {40, 50};

  std::cout << "--CIRCLE--" << std::endl;
  circle.move(newPoint);
  viewInfo(circle);

  return 0;
}
