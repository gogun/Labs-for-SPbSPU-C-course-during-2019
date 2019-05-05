#include <iostream>
#include <cassert>

#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

std::ostream & operator <<(std::ostream & out, const rectangle_t rect)
{
  out << "Frame rect width = " << rect.width << " " <<
    "height = " << rect.height << " " <<
    "centreX = " << rect.pos.x << " " <<
    "centreY = " << rect.pos.y << std::endl;

  return out;
}

void printShape(const Shape *shape)
{
  assert(shape != nullptr);
  std::cout << "Area = " << shape->getArea() << std::endl;
  std::cout << shape->getFrameRect();
}

void demonstrateShapeCapabilities(Shape *shape)
{
  assert(shape != nullptr);
  std::cout << "=== " << shape->getName() << " ===" << std::endl;
  printShape(shape);
  std::cout << "Set new centre point" << std::endl;
  shape->move({100, 50});
  printShape(shape);
  std::cout << "Delta move" << std::endl;
  shape->move(10, 30);
  printShape(shape);
  std::cout << "===" << std::endl;
}

int main()
{
  point_t circleCentre = {5, 8};
  const double circleRadius = 5;

  point_t rectangleCentre = {12, 30};
  const double rectangleWidth = 20;
  const double rectangleHeight = 10;

  point_t trianglePointA = {1, 20};
  point_t trianglePointB = {30, 4};
  point_t trianglePointC = {4, 50};

  Circle circle(circleRadius, circleCentre);
  Rectangle rectangle(rectangleWidth, rectangleHeight, rectangleCentre);
  Triangle triangle(trianglePointA, trianglePointB, trianglePointC);

  demonstrateShapeCapabilities(&circle);
  demonstrateShapeCapabilities(&rectangle);
  demonstrateShapeCapabilities(&triangle);

  return 0;
}
