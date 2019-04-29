#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printArea(const Shape& shape)
{
  std::cout << "Area - " << shape.getArea() << '\n';
}

void printFrameRect(const Shape& shape)
{
  std::cout << "Frame rectangle width - " << shape.getFrameRect().width << '\n';
  std::cout << "Frame rectangle height - " << shape.getFrameRect().height << '\n';
}

void printPosition(const Shape& shape)
{
  std::cout << "Position - " << shape.getFrameRect().pos.x << ',' << shape.getFrameRect().pos.y << '\n';
}

int main()
{
  point_t center{0, 0};

  Rectangle rectangle(center, 2, 4);
  std::cout << "RECTANGLE:\n";
  printArea(rectangle);
  printFrameRect(rectangle);
  rectangle.move({1, 1});
  rectangle.move(2, 2);
  printPosition(rectangle);
  std::cout << '\n';

  Circle circle(center, 3);
  std::cout << "CIRCLE:\n";
  printArea(circle);
  printFrameRect(circle);
  circle.move({1, 1});
  circle.move(2, 2);
  printPosition(circle);
  std::cout << '\n';

  Triangle triangle(center, 2, 4);
  std::cout << "TRIANGLE:\n";
  printArea(triangle);
  printFrameRect(triangle);
  triangle.move({1, 1});
  triangle.move(2, 2);
  printPosition(triangle);
}
