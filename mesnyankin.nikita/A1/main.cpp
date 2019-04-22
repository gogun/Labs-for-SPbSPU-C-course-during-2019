#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void moveFigure(Shape * shape, const double &x, const double &y)
{
  std::cout << "Before movement: " << shape->getFrameRect().pos.x << " | " << shape->getFrameRect().pos.y << "\n";
  shape->move(x, y);
  std::cout << "After movement: " << shape->getFrameRect().pos.x << " | " << shape->getFrameRect().pos.y << "\n";
}

void showStatus(const Shape * shape)
{
  std::cout << "Current shape area is: " << shape->getArea() << "\n";
  std::cout << "Current shape centre is in: "
      << shape->getFrameRect().pos.x << "," << shape->getFrameRect().pos.y << "\n";
}

int main()
{
  Rectangle rectangle_object(7, 7, {20, 20});

  showStatus(&rectangle_object);
  moveFigure(&rectangle_object, 5, 5);
  showStatus(&rectangle_object);
  std::cout << "======================================" << "\n";

  Circle circle_object(5, 5, 5);

  showStatus(&circle_object);
  moveFigure(&circle_object, 3, 2);
  showStatus(&circle_object);
  std::cout << "======================================" << "\n";

  Triangle triangle_object({1, 1}, {2, 3}, {3, 2});

  showStatus(&triangle_object);
  triangle_object.showCoordinates();
  moveFigure(&triangle_object, 7, 8);
  showStatus(&triangle_object);
  triangle_object.showCoordinates();

  return 0;
}
