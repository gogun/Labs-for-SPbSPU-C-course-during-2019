#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void showParametrsShape(frolov::Shape *shape)
{
  std::cout << "Area of Shape= " << shape->getArea() << "\n";
  std::cout << "Frame: " << "\n";
  frolov::rectangle_t frame = shape->getFrameRect();
  std::cout << "Height= " << frame.height << "\n";
  std::cout << "Width= " << frame.width << "\n";
  std::cout << "Point of Center in x-axis= " << frame.pos.x << "\n";
  std::cout << "Point of Center in y-axis= " << frame.pos.y << "\n";
  shape->move(4,5);
  shape->showPoint();
  shape->move({4, 5});
  shape->showPoint();
  shape->scale(2);
  std::cout << "Area after scale= " << shape->getArea() << "\n";
  std::cout << "\n";
}

int main()
{
  frolov::Circle circle({3, 4}, 5);
  showParametrsShape(&circle);

  frolov::Triangle triangle({4, 5}, {3, 5}, {6, 7});
  showParametrsShape(&triangle);

  frolov::Rectangle rectangle({4, 5}, 7, 9);
  showParametrsShape(&rectangle);

  return 0;
}
