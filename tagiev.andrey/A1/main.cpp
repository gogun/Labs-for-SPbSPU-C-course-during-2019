#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfo(const Shape *shape)
{
  assert(shape != nullptr);

  const rectangle_t frame = shape->getFrameRect();
  std::cout << "Area of shape: " << shape->getArea() << '\n';
  std::cout << "Width of frame: " << frame.width << '\n';
  std::cout << "Height of frame: " << frame.height << '\n';
  std::cout << "Center: " << frame.pos.x << ", " << frame.pos.y << "\n\n";
}

int main()
{
  Rectangle rectangle({123, 100}, 5, 3);
  printInfo(&rectangle);
  point_t newCenter = {1, 2};
  rectangle.move(newCenter);
  rectangle.move(10, 20);
  printInfo(&rectangle);

  Circle circle({11.1, 12.2}, 4.4);
  printInfo(&circle);
  newCenter = {10, 20};
  circle.move(newCenter);
  circle.move(1, 2);
  printInfo(&circle);

  return 0;
}
