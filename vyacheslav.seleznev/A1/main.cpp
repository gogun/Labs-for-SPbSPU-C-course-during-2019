#include <iostream>

#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

std::ostream& operator<<(std::ostream& out , const rectangle_t rect)
{
  out << "Frame rect width = " << rect.width << " " <<
    "height = " << rect.height << " " <<
    "centreX = " << rect.pos.x << " " <<
    "centreY = " << rect.pos.y << std::endl;

  return out;
}

int main()
{
  point_t circleCentre = {5, 8};
  const double circleRadius = 5;

  point_t rectangleCentre = {25, 30};
  const double rectangleWidth = 20;
  const double rectangleHeight = 10;

  Shape *circle = new Circle(circleRadius, circleCentre);
  Shape *rectangle = new Rectangle(rectangleWidth, rectangleHeight, rectangleCentre);

  std::cout << "Circle area = " << circle->getArea() << std::endl;
  std::cout << "Rectangle area = " << rectangle->getArea() << std::endl;

  std::cout << "Circle " << circle->getFrameRect();
  std::cout << "Rectangle " << rectangle->getFrameRect();

  std::cout << "Set new centre point" << std::endl;

  circle->move({100, 50});
  rectangle->move({500, 999});

  std::cout << "Circle " << circle->getFrameRect();
  std::cout << "Rectangle " << rectangle->getFrameRect();

  std::cout << "Delta move" << std::endl;

  circle->move(10, 30);
  rectangle->move(-40, -99);

  std::cout << "Circle " << circle->getFrameRect();
  std::cout << "Rectangle " << rectangle->getFrameRect();

  delete circle;
  delete rectangle;

  return 0;
}
