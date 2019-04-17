#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void showParametrsShape(Shape *shape)
{
  std::cout << "Area of Shape= " << shape->getArea() << "\n";
  std::cout << "Frame: " << "\n";
  rectangle_t frame = shape->getFrameRect();
  std::cout << "Height= " << frame.height << "\n";
  std::cout << "Width= " << frame.width << "\n";
  std::cout << "Point of Center in x-axis= " << frame.pos.x << "\n";
  std::cout << "Point of Center in y-axis= " << frame.pos.y << "\n";
  shape->move(4,5);
  shape->showPoint();
  shape->move({4, 5});
  shape->showPoint();
  std::cout << "\n";
}

int main()
{
  Circle circle({3, 4}, 5);
  showParametrsShape(&circle);

  Triangle triangle({4, 5}, {3, 5}, {6, 7});
  showParametrsShape(&triangle);

  Rectangle rectangle({4, 5}, 7, 9);
  showParametrsShape(&rectangle);

  return 0;
}
