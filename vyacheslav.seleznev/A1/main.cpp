#include <iostream>

#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

std::ostream& operator << (std::ostream& out , const rectangle_t rect)
{
  out << "Frame rect width = " << rect.width << " " <<
    "height = " << rect.height << " " <<
    "centreX = " << rect.pos.x << " " <<
    "centreY = " << rect.pos.y << std::endl;

  return out;
}

void stupidPolimorphicMethod(Shape & obj)
{
  std::cout << "Area = " << obj.getArea() << std::endl;
  std::cout << "Frame rect " << obj.getFrameRect();
}

int main()
{
  point_t circleCentre = {5, 8};
  const double circleRadius = 5;

  point_t rectangleCentre = {25, 30};
  const double rectangleWidth = 20;
  const double rectangleHeight = 10;

  point_t triangleCentre = {44, 77};
  point_t trianglePointA = {88, 56};

  point_t trianglePointB = {11, 90};

  point_t trianglePointC = {39, 8};

  Circle circle(circleRadius, circleCentre);
  Rectangle rectangle(rectangleWidth, rectangleHeight, rectangleCentre);
  Triangle triangle(trianglePointA, trianglePointB, trianglePointC, triangleCentre);

  std::cout << "=== Circle ===" << std::endl;
  stupidPolimorphicMethod(circle);
  std::cout << "Set new centre point" << std::endl;
  
  circle.move({100, 50});
  stupidPolimorphicMethod(circle);

  std::cout << "Delta move" << std::endl;

  circle.move(10, 30);
  stupidPolimorphicMethod(circle);

  std::cout << "===" << std::endl;

  std::cout << "=== Rectangle ===" << std::endl;
  stupidPolimorphicMethod(rectangle);
  std::cout << "Set new centre point" << std::endl;
  
  rectangle.move({500, 999});
  stupidPolimorphicMethod(rectangle);

  std::cout << "Delta move" << std::endl;

  rectangle.move(-40, -99);
  stupidPolimorphicMethod(rectangle);

  std::cout << "===" << std::endl;

  std::cout << "=== Triangle ===" << std::endl;
  stupidPolimorphicMethod(triangle);
  std::cout << "Set new centre point" << std::endl;

  triangle.move({385, 444});
  stupidPolimorphicMethod(triangle);

  std::cout << "Delta move" << std::endl;

  triangle.move(-88, -12);
  stupidPolimorphicMethod(triangle);

  std::cout << "===" << std::endl;

  return 0;
}
