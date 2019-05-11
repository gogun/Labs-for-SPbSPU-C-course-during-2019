#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  nazarov::Rectangle rectangle({0, 0}, 20, 10);
  nazarov::Shape *rectPointer = &rectangle;

  rectPointer->printFeatures();
  rectPointer->move(10, 20);
  std::cout << "Rectangle has been moved by dx and dy\n\n";
  rectPointer->printFeatures();
  rectPointer->move({10, 20});
  std::cout << "Rectangle has been moved by coordinates\n\n";
  rectPointer->printFeatures();
  rectPointer->scale(4);
  std::cout << "Rectangle has been scaled\n\n";
  rectPointer->printFeatures();

  nazarov::Circle circle({0, 0}, 10);
  nazarov::Shape *circlePointer = &circle;

  circlePointer->printFeatures();
  circlePointer->move(10, 20);
  std::cout << "Circle has been moved by dx and dy\n\n";
  circlePointer->printFeatures();
  circlePointer->move({10, 20});
  std::cout << "Circle has been moved by coordinates\n\n";
  circlePointer->printFeatures();
  circlePointer->scale(3);
  std::cout << "Circle has been scaled\n\n";
  circlePointer->printFeatures();

  nazarov::Triangle triangle({0, 0}, {10, 10}, {20, -10});
  nazarov::Shape *trianglePointer = &triangle;

  trianglePointer->printFeatures();
  trianglePointer->move(10, 20);
  std::cout << "Triangle has been moved by dx and dy\n\n";
  trianglePointer->printFeatures();
  trianglePointer->move({10, 20});
  std::cout << "Triangle has been moved by coordinates\n\n";
  trianglePointer->printFeatures();
  trianglePointer->scale(2);
  std::cout << "Triangle has been scaled\n\n";
  trianglePointer->printFeatures();

  return 0;
}
