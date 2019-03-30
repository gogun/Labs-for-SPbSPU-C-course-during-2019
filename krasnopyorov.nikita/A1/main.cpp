#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void writeFrameRect(const rectangle_t &frameRect)
{
  std::cout << "Frame Rectangle:" << std::endl;
  std::cout << "Coordinates of centre: (" << frameRect.pos.x << "," << frameRect.pos.y << ")" << std::endl;
  std::cout << "Size of frame rectagle: " << std::endl;
  std::cout << "Height: " << frameRect.height << std::endl;
  std::cout << "Width: " << frameRect.width << std::endl;
}

int main()
{
  Circle objCirc(1.0, {0, 0});
  Shape *pointer = &objCirc;
  double dx = 2.1, dy = 3.3;
  point_t dot = {0, 0};

  std::cout << "Square of circle:" << std::endl;
  std::cout << pointer->getArea() << std::endl;
  rectangle_t frameRect = objCirc.getFrameRect();
  writeFrameRect(frameRect);
  pointer->move(dx, dy);
  objCirc.writeChanges();
  pointer->move(dot);
  objCirc.writeChanges();

  std::cout << std::endl;
  std::cout << std::endl;

  Rectangle objRect({2.5, 1.0, {0, 0}});
  pointer = &objRect;

  std::cout << "Square of rectangle:" << std::endl;
  std::cout << pointer->getArea() << std::endl;
  frameRect = pointer->getFrameRect();
  writeFrameRect(frameRect);
  pointer->move(dx, dy);
  objRect.writeChanges();
  pointer->move(dot);
  objRect.writeChanges();

  std::cout << std::endl;

  return 0;
}
