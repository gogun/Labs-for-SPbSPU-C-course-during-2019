#include <iostream>
#include <cassert>

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void printInfo(const tagiev::Shape *shape)
{
  assert(shape != nullptr);

  const tagiev::rectangle_t frame = shape->getFrameRect();

  std::cout << "Area of shape: " << shape->getArea() << '\n';
  std::cout << "Width of frame: " << frame.width << '\n';
  std::cout << "Height of frame: " << frame.height << '\n';
  std::cout << "Center: " << frame.pos.x << ", " << frame.pos.y << "\n\n";
}

int main()
{
  tagiev::Rectangle rectangle({123.0, 100.0}, 5.0, 3.0);

  printInfo(&rectangle);
  const tagiev::point_t newCenter1 = {1.0, 2.0};
  rectangle.move(newCenter1);
  rectangle.move(10.0, 20.0);
  rectangle.scale(2.0);
  printInfo(&rectangle);

  tagiev::Circle circle({11.1, 12.2}, 4.4);

  printInfo(&circle);
  const tagiev::point_t newCenter2 = {10.0, 20.0};
  circle.move(newCenter2);
  circle.move(1.0, 2.0);
  circle.scale(2.0);
  printInfo(&circle);

  tagiev::Triangle triangle({0.0, 0.0}, {0.0, 4.0}, {3.0, 4.0});

  printInfo(&triangle);
  const tagiev::point_t newCenter3 = {100.0, 200.0};
  triangle.move(newCenter3);
  triangle.move(0.1, 0.2);
  triangle.scale(2.0);
  printInfo(&triangle);

  return 0;
}
