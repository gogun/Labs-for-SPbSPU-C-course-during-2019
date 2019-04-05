#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <iostream>

int main()
{
  point_t center = {1,4};
  std::cout << "Rectangle \n";
  Rectangle rectangle(center,2,6);
  rectangle.prInf();
  rectangle.getArea();
  point_t newPoint;
  newPoint.x = 3;
  newPoint.y = 8;
  rectangle.move(3,5);
  rectangle.move(newPoint);
  rectangle.getFrameRect();
  rectangle.prInf();
  std::cout << '\n';
  std::cout << "Circle \n";
  Circle circle(center,3);
  circle.prInf();
  circle.getArea();
  circle.move(2,2);
  circle.move(newPoint);
  circle.getFrameRect();
  circle.prInf();
  std::cout<<"\n";
  std::cout << "Triangle \n";
  point_t A = { 2,2 }, B = { 3,4 }, C = { 5,3 };
  Triangle triangle(A,B,C);
  triangle.prInf();
  triangle.center(A,B,C);
  triangle.getArea();
  triangle.move(2,3);
  triangle.move(newPoint);
  triangle.getFrameRect();
  triangle.prInf();
  return 0;
}