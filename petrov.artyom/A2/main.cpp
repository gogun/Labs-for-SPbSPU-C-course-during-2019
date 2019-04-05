#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  petrov::point_t centre {10, 10};
  const double scaleFactor = 2;
  const int radius = 5;

  petrov::Circle circle = petrov::Circle(centre, radius);

  double areaBeforeScaling = circle.getArea();
  circle.scale(2);
  double areaAfterScaling = circle.getArea();

  std::cout << "Area of circle (initial radius: " << radius << "):" << std::endl
      << "before scaling: " << areaBeforeScaling << std::endl
      << "after scaling " << areaAfterScaling << std::endl
      << "intended area scale factor: " << scaleFactor * scaleFactor << std::endl
      << "actual area scale factor: " << areaAfterScaling / areaBeforeScaling << std::endl;

  std::cout << "-------------------------------------------------------------------------" << std::endl;

  const int width = 5;
  const int height = 10;
  petrov::Rectangle rectangle = petrov::Rectangle(centre, width, height);

  areaBeforeScaling = rectangle.getArea();
  rectangle.scale(2);
  areaAfterScaling = rectangle.getArea();

  std::cout << "Area of rectangle (initial width: " << width
      << ", initial height: " << height << "):"  << std::endl
      << "before scaling: " << areaBeforeScaling << std::endl
      << "after scaling " << areaAfterScaling << std::endl
      << "intended area scale factor: " << scaleFactor * scaleFactor << std::endl
      << "actual area scale factor: " << areaAfterScaling / areaBeforeScaling << std::endl;


  return 0;
}
