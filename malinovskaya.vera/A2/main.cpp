#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  malinovskaya::Circle objectCircle({4.0, 2.0}, 3.0);
  malinovskaya::Shape *shapePointer = &objectCircle;
  std::cout << "Circle:" << std::endl;
  std::cout << std::endl;
  std::cout << "Area: " << shapePointer->getArea() << std::endl;
  std::cout << "Frame (width): " << shapePointer->getFrameRect().width << std::endl;
  std::cout << "Frame (height): " << shapePointer->getFrameRect().height << std::endl;
  shapePointer->print();
  std::cout << std::endl;
  std::cout << "Shift: dx = " << -2 << ", dy = " << 4 << std::endl;
  shapePointer->move(-2.0, 4.0);
  shapePointer->print();
  std::cout << std::endl;
  std::cout << "Move to (" << 0 << ", " << -6 << ")" << std::endl;
  shapePointer->move({0.0, -6.0});
  shapePointer->print();

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Scale with a coefficient of 3" << std::endl;
  shapePointer->scale(3.0);
  std::cout << std::endl;
  std::cout << "Area: " << shapePointer->getArea() << std::endl;
  std::cout << "Frame (width): " << shapePointer->getFrameRect().width << std::endl;
  std::cout << "Frame (height): " << shapePointer->getFrameRect().height << std::endl;
  shapePointer->print();

  std::cout << std::endl;
  std::cout << std::endl;

  malinovskaya::Rectangle objectRectangle({3.0, 4.0, {5.0, 8.0}});
  shapePointer = &objectRectangle;
  std::cout << "Rectangle:" << std::endl;
  std::cout << std::endl;
  std::cout << "Area: " << shapePointer->getArea() << std::endl;
  std::cout << "Frame (width): " << shapePointer->getFrameRect().width << std::endl;
  std::cout << "Frame (height): " << shapePointer->getFrameRect().height << std::endl;
  shapePointer->print();
  std::cout << std::endl;
  std::cout << "Shift: dx = " << 8 << ", dy = " << 2 << std::endl;
  shapePointer->move(8.0, 2.0);
  shapePointer->print();
  std::cout << std::endl;
  std::cout << "Move to (" << -5 << ", " << -10 << ")" << std::endl;
  shapePointer->move({-5.0, -10.0});
  shapePointer->print();

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Scale with a coefficient of 4.5" << std::endl;
  shapePointer->scale(4.5);
  std::cout << std::endl;
  std::cout << "Area: " << shapePointer->getArea() << std::endl;
  std::cout << "Frame (width): " << shapePointer->getFrameRect().width << std::endl;
  std::cout << "Frame (height): " << shapePointer->getFrameRect().height << std::endl;
  shapePointer->print();

  return 0;
}
