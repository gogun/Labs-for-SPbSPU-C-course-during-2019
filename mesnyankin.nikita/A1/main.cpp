#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Rectangle rectangle_object(7, 7, {20, 20});
  Shape *objPointer = &rectangle_object;

  std::cout << "Rectangle characteristics: " << "\n";
  std::cout << "Area: " << objPointer->getArea() << "\n";
  std::cout << "Frame rectangle values: " << "\n";
  std::cout << "Width: " << objPointer->getFrameRect().width << "\n";
  std::cout << "Height: " << objPointer->getFrameRect().height << "\n";

  std::cout << "Centre position: " << rectangle_object.getPos().x << ","
    << rectangle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  objPointer->move(1, 1);
  std::cout << "Centre after displacement: " << rectangle_object.getPos().x << ","
    << rectangle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  objPointer->move({1, 1});
  std::cout << "Centre after movement: " << rectangle_object.getPos().x << ","
    << rectangle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  std::cout << "======================================" << "\n";

  Circle circle_object(5, 5, 5);
  objPointer = &circle_object;

  std::cout << "Circle characteristics: " << "\n";
  std::cout << "Area: " << objPointer->getArea() << "\n";
  std::cout << "Frame rectangle values: " << "\n";
  std::cout << "Width: " << objPointer->getFrameRect().width << "\n";
  std::cout << "Height: " << objPointer->getFrameRect().height << "\n";
  std::cout << "Centre position: " << circle_object.getPos().x << ","
    << circle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  objPointer->move(6, 3);
  std::cout << "Centre after displacement: " << circle_object.getPos().x << ","
    << circle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  objPointer->move({2, 2});
  std::cout << "Centre after movement: " << circle_object.getPos().x << ","
    << circle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  std::cout << "======================================" << "\n";

  Triangle triangle_object({1, 1}, {2, 3}, {3, 4});
  objPointer = &triangle_object;

  std::cout << "Triangle characteristics: " << "\n";
  std::cout << "Area: " << objPointer->getArea() << "\n";
  std::cout << "Frame rectangle values: " << "\n";
  std::cout << "Width: " << objPointer->getFrameRect().width << "\n";
  std::cout << "Height: " << objPointer->getFrameRect().height << "\n";

  std::cout << "Centre position: " << triangle_object.getPos().x << ","
    << triangle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  objPointer->move(6, 3);
  std::cout << "Centre after displacement: " << triangle_object.getPos().x << ","
    << triangle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  objPointer->move({ 2, 2 });
  std::cout << "Centre after movement: " << triangle_object.getPos().x << ","
    << triangle_object.getPos().y << "\n";
  std::cout << "Centre (frame rectangle): " << objPointer->getFrameRect().pos.x << ","
    << objPointer->getFrameRect().pos.y << "\n";
  std::cout << "======================================" << "\n";

  return 0;
}
