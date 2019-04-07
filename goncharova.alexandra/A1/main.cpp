#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  point_t dot = {3, 4};
  Circle circle1(dot, 15);
  Rectangle rectangle1(dot, 10, 10);

  std::cout << "Area of circle1: ";
  std::cout << circle1.getArea() << "\n";
  std::cout << "Height of frame rectangle: ";
  std::cout << circle1.getFrameRect().height << "\n";
  std::cout << "Width of frame rectangle: ";
  std::cout << circle1.getFrameRect().width << "\n";

  point_t movePoint = { 5,6 };
  circle1.move(movePoint);
  std::cout << "Circle moved to: x:" << circle1.center_.x;
  std::cout << ", y:" << circle1.center_.y << "\n";

  circle1.move(7.0, 8.0);
  std::cout << "Circle moved to: x:" << circle1.center_.x;
  std::cout << ", y:" << circle1.center_.y << "\n";

  std::cout << "-----" << "\n";

  std::cout << "Area of rectangle1: ";
  std::cout << rectangle1.getArea() << "\n";
  std::cout << "Height of frame rectangle: ";
  std::cout << rectangle1.getFrameRect().height << "\n";
  std::cout << "Width of frame rectangle: ";
  std::cout << rectangle1.getFrameRect().width << "\n";

  rectangle1.move(movePoint);
  std::cout << "Rectangle moved to: x:" << rectangle1.center_.x;
  std::cout << ", y:" << rectangle1.center_.y << "\n";

  rectangle1.move(7.0, 8.0);
  std::cout << "Rectangle moved to: x:" << rectangle1.center_.x;
  std::cout << ", y:" << rectangle1.center_.y << "\n";

  return 0;
}
