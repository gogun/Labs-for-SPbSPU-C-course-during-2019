#include <cassert>
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void showStatus(const Shape *shape)
{
  assert(shape != nullptr);
  std::cout << "Current area and frame rectangle are: ";
  std::cout << shape->getArea() << "\n";
  rectangle_t frame = shape->getFrameRect();
  std::cout << frame.width << " | " << frame.height << " | " << frame.pos.x << "," << frame.pos.y << "\n";
}

void moveFigure(Shape *shape, const double x, const double y)
{
  assert(shape != nullptr);
  shape->move(x,y);
}

int main()
{
  Rectangle rectangle_object(7, 7, {20,20});

  showStatus(&rectangle_object);
  moveFigure(&rectangle_object, 3, 3);
  showStatus(&rectangle_object);

  Circle circle_object(5,5,5);

  showStatus(&circle_object);
  moveFigure(&circle_object, 3, 3);
  showStatus(&circle_object);

  Triangle triangle_object({5,5}, {3,2}, {4,4});

  showStatus(&triangle_object);
  moveFigure(&triangle_object, 3, 3);
  showStatus(&triangle_object);

  return 0;
}
