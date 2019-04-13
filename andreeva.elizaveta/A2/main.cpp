#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  andreeva::Circle circle({1.0, 1.0}, 5.0);
  andreeva::Shape *shapePtr = &circle;
  std::cout << "Circle area " << shapePtr->getArea() << '\n';
  shapePtr->scale(4.0);
  std::cout << "Circle area " << shapePtr->getArea() << '\n';
  andreeva::rectangle_t frameRect = shapePtr->getFrameRect();
  std::cout << "Frame Rectangle X " << frameRect.pos.x << '\n';
  std::cout << "Frame Rectangle Y " << frameRect.pos.y << '\n';
  std::cout << "Frame Rectangle Height " << frameRect.height << '\n';
  std::cout << "Frame Rectangle Width " << frameRect.width << '\n';
  shapePtr->move(1.0, 3.5);
  frameRect = shapePtr->getFrameRect();
  std::cout << "Frame Rectangle X after moving " << frameRect.pos.x << '\n';
  std::cout << "Frame Rectangle Y after moving " << frameRect.pos.y << '\n';

  andreeva::Rectangle rectangle({2.0, 2.0}, 5.0, 6.0);
  shapePtr = &rectangle;
  std::cout << "Rectangle area " << shapePtr->getArea() << '\n';
  shapePtr->scale(5.0);
  std::cout << "Rectangle area " << shapePtr->getArea() << '\n';
  frameRect = shapePtr->getFrameRect();
  std::cout << "Frame Rectangle X " << frameRect.pos.x << '\n';
  std::cout << "Frame Rectangle Y " << frameRect.pos.y << '\n';
  std::cout << "Frame Rectangle Width " << frameRect.width << '\n';
  std::cout << "Frame Rectangle Height " << frameRect.height << '\n';
  shapePtr->move({3.0, 4.0});
  frameRect = shapePtr->getFrameRect();
  std::cout << "Frame Rectangle X after moving " << frameRect.pos.x << '\n';
  std::cout << "Frame Rectangle Y after moving " << frameRect.pos.y << '\n';
  return 0;
}
