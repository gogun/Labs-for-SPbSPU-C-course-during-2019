#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  Circle circle({3, 4}, 5);
  Shape *shape = &circle;
  std::cout << "Area of Circle= " << shape->getArea() << "\n";
  std::cout << "Frame: " << "\n";
  rectangle_t frame = shape->getFrameRect();
  std::cout << "Height= " << frame.height << "\n";
  std::cout << "Width= " << frame.width << "\n";
  std::cout << "Point of Center in x-axis= " << frame.center_.x << "\n";
  std::cout << "Point of Center in y-axis= " << frame.center_.y << "\n";
  shape->move(4,5);
  shape->showPoint();
  shape->move({4, 5});
  shape->showPoint();

  Triangle triangle({4, 5}, {3, 5}, {6, 7});
  shape = &triangle;
  std::cout << "Area of Triangle= " << shape->getArea() << "\n";
  std::cout << "Frame: " << "\n";
  frame = shape->getFrameRect();
  std::cout << "Height= " << frame.height << "\n";
  std::cout << "Width= " << frame.width << "\n";
  std::cout << "Point of Center in x-axis= " << frame.center_.x << "\n";
  std::cout << "Point of Center in y-axis= " << frame.center_.y << "\n";
  shape->move(4,5);
  shape->showPoint();
  shape->move({4, 5});
  shape->showPoint();

  Rectangle rectangle({4, 5}, 7, 9);
  shape = &rectangle;
  std::cout << "Area of Triangle= " << shape->getArea() << "\n";
  std::cout << "Frame: " << "\n";
  frame = shape->getFrameRect();
  std::cout << "Height= " << frame.height << "\n";
  std::cout << "Width= " << frame.width << "\n";
  std::cout << "Point of Center in x-axis= " << frame.center_.x << "\n";
  std::cout << "Point of Center in y-axis= " << frame.center_.y << "\n";
  shape->move(4,5);
  shape->showPoint();
  shape->move({4, 5});
  shape->showPoint();

  return 0;
}
