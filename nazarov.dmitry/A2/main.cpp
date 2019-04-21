#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  nazarov::Rectangle rect({ 0, 0 }, 20, 10);
  nazarov::Shape *shapePointer = &rect;

  shapePointer->printFeatures();
  shapePointer->move(10, 20);
  std::cout << "  Rectangle has been moved by dx and dy\n\n";
  shapePointer->printFeatures();
  shapePointer->move({ 10, 20 });
  std::cout << "  Rectangle has been moved by coordinates\n\n";
  shapePointer->printFeatures();
  shapePointer->scale(4);
  std::cout << "  Rectangle has been scaled\n\n";
  shapePointer->printFeatures();

  nazarov::Circle circle({ 0, 0 }, 10);
  shapePointer = &circle;

  shapePointer->printFeatures();
  shapePointer->move(10, 20);
  std::cout << "  Circle has been moved by dx and dy\n\n";
  shapePointer->printFeatures();
  shapePointer->move({10, 20});
  std::cout << "  Circle has been moved by coordinates\n\n";
  shapePointer->printFeatures();
  shapePointer->scale(3);
  std::cout << "  Circle has been scaled\n\n";
  shapePointer->printFeatures();

  return 0;
}
