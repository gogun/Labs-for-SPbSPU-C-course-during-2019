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

void polimorphicMethod(Shape & obj)
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

  point_t triangleCentre = {44, 32};
  point_t trianglePointA = {0, 1};

  point_t trianglePointB = {32, 21};

  point_t trianglePointC = {2, 5};

  Circle circle(circleRadius, circleCentre);
  Rectangle rectangle(rectangleWidth, rectangleHeight, rectangleCentre);
  Triangle triangle(trianglePointA, trianglePointB, trianglePointC, triangleCentre);

  std::cout << "=== Circle ===" << std::endl;
  polimorphicMethod(circle);
  std::cout << "Set new centre point" << std::endl;
  
  circle.move({100, 50});
  polimorphicMethod(circle);

  std::cout << "Delta move" << std::endl;

  circle.move(10, 30);
  polimorphicMethod(circle);

  std::cout << "===" << std::endl;

  std::cout << "=== Rectangle ===" << std::endl;
  polimorphicMethod(rectangle);
  std::cout << "Set new centre point" << std::endl;
  
  rectangle.move({500, 999});
  polimorphicMethod(rectangle);

  std::cout << "Delta move" << std::endl;

  rectangle.move(-40, -99);
  polimorphicMethod(rectangle);

  std::cout << "===" << std::endl;

  std::cout << "=== Triangle ===" << std::endl;
  polimorphicMethod(triangle);
  std::cout << "Set new centre point" << std::endl;

  triangle.move({385, 444});
  polimorphicMethod(triangle);

  std::cout << "Delta move" << std::endl;

  triangle.move(-88, -12);
  polimorphicMethod(triangle);

  std::cout << "===" << std::endl;

  return 0;
}
