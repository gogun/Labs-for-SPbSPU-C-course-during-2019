#include <iostream>

#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

std::ostream & operator <<(std::ostream & out , const seleznev::rectangle_t rect)
{
  out << "Frame rect width = " << rect.width << " " <<
    "height = " << rect.height << " " <<
    "centreX = " << rect.pos.x << " " <<
    "centreY = " << rect.pos.y << std::endl;

  return out;
}

void printShape(seleznev::Shape *shape)
{
  std::cout << "Area = " << shape->getArea() << std::endl;
  std::cout << "Frame rect " << shape->getFrameRect();
}

void demonstrateShapeCapabilities(seleznev::Shape *shape, std::string figure)
{
  std::cout << figure << std::endl;
  printShape(shape);
  std::cout << "Set new centre point" << std::endl;
  shape->move({100, 50});
  printShape(shape);
  std::cout << "Delta move" << std::endl;
  shape->move(10, 30);
  printShape(shape);
  std::cout << "Scale" << std::endl;
  shape->scale(4);
  printShape(shape);
  std::cout << "===" << std::endl;
}

int main()
{
  seleznev::point_t circleCentre = {5, 8};
  const double circleRadius = 5;

  seleznev::point_t rectangleCentre = {12, 30};
  const double rectangleWidth = 20;
  const double rectangleHeight = 10;

  seleznev::point_t trianglePointA = {1, 20};
  seleznev::point_t trianglePointB = {30, 4};
  seleznev::point_t trianglePointC = {4, 50};

  seleznev::Circle circle(circleRadius, circleCentre);
  seleznev::Rectangle rectangle(rectangleWidth, rectangleHeight, rectangleCentre);
  seleznev::Triangle triangle(trianglePointA, trianglePointB, trianglePointC);

  demonstrateShapeCapabilities(&circle, "=== Circle ===");
  demonstrateShapeCapabilities(&rectangle, "=== Rectangle ===");
  demonstrateShapeCapabilities(&triangle, "=== Triangle ===");

  return 0;
}
