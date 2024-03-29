#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  point_t dot = { 3, 4 };
  Circle circle1(dot, 15);
  Rectangle rectangle1(dot, 10, 10);
  Triangle triangle1({ 0, 0 }, { 3, 2 }, { 1, 6 });

  Shape* shape1 = &circle1;
  std::cout << "Area of circle1: ";
  std::cout << shape1->getArea() << "\n";
  std::cout << "Height of frame rectangle: ";
  std::cout << shape1->getFrameRect().height << "\n";
  std::cout << "Width of frame rectangle: ";
  std::cout << shape1->getFrameRect().width << "\n";

  point_t movePoint = { 5,6 };
  shape1->move(movePoint);
  std::cout << "Circle moved to: ";
  shape1->inform();

  shape1->move(7.0, 8.0);
  std::cout << "Circle moved to: ";
  shape1->inform();

  std::cout << "-----" << "\n";

  shape1 = &rectangle1;
  std::cout << "Area of rectangle1: ";
  std::cout << shape1->getArea() << "\n";
  std::cout << "Height of frame rectangle: ";
  std::cout << shape1->getFrameRect().height << "\n";
  std::cout << "Width of frame rectangle: ";
  std::cout << shape1->getFrameRect().width << "\n";

  shape1->move(movePoint);
  std::cout << "Rectangle moved to: ";
  shape1->inform();

  shape1->move(7.0, 8.0);
  std::cout << "Rectangle moved to: ";
  shape1->inform();

  std::cout << "-----" << "\n";

  shape1 = &triangle1;
  std::cout << "Area of triangle1: ";
  std::cout << shape1->getArea() << "\n";
  std::cout << "Height of frame triangle: ";
  std::cout << shape1->getFrameRect().height << "\n";
  std::cout << "Width of frame triangle: ";
  std::cout << shape1->getFrameRect().width << "\n";

  shape1->move(movePoint);
  std::cout << "Triangle moved to: ";
  shape1->inform();

  shape1->move(7.0, 8.0);
  std::cout << "Triangle moved to: ";
  shape1->inform();

  return 0;
}
