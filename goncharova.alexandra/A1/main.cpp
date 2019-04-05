#include <iostream>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "base-types.hpp"

int main()
{
  point_t dot = {3, 4};
  Circle circle1(dot, 15);
  std::cout << "Area of circle1: " << circle1.getArea() << std::endl;
  std::cout << "Height of frame rectangle: " << circle1.getFrameRect().height << std::endl;
  std::cout << "Width of frame rectangle: " << circle1.getFrameRect().width << std::endl;
  point_t movePoint = { 5,6 };
  circle1.move(movePoint);
  std::cout << "Circle moved to: x:" << circle1.center_.x
  << ", y:" << circle1.center_.y << std::endl;
  circle1.move(7.0, 8.0);
  std::cout << "Circle moved to: x:" << circle1.center_.x
  << ", y:" << circle1.center_.y << std::endl;
  std::cout << "---" << std::endl;

  Rectangle rectangle1(dot, 10, 10);
  std::cout << "Area of rectangle1: " << rectangle1.getArea() << std::endl;
  std::cout << "Height of frame rectangle: " << rectangle1.getFrameRect().height
  << std::endl;
  std::cout << "Width of frame rectangle: " << rectangle1.getFrameRect().width
  << std::endl;
  rectangle1.move(movePoint);
  std::cout << "Rectangle moved to: x:" << rectangle1.center_.x 
  << ", y:" << rectangle1.center_.y << std::endl;
  rectangle1.move(7.0, 8.0);
  std::cout << "Rectangle moved to: x:" << rectangle1.center_.x 
  << ", y:" << rectangle1.center_.y << std::endl;

  return 0;
}
