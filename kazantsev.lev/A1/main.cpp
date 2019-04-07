#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void printFrameInfo(const rectangle_t &frame)
{
  std::cout << "Frame is:" << "\n";
  std::cout << "Width = " << frame.width << " Height = " << frame.height << "\n";
  std::cout << "Centre is in " << " X= " << frame.pos.x << " Y= " << frame.pos.y << "\n";
}

int main()
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Shape* ptr = &oRectangle;
  ptr->printShapeInfo();
  std::cout << "Area= " << ptr->getArea() << "\n";
  ptr->move({ 5, 5 });
  std::cout << "After moving to {5,5}: " << "\n";
  ptr->printShapeInfo();
  ptr->move(2, 3);
  std::cout << "After moving on dx=2, dy=3" << "\n";
  ptr->printShapeInfo();
  printFrameInfo(ptr->getFrameRect());
  std::cout << "\n";

  Circle oCircle{ { 1, 1 }, 6 };
  ptr = &oCircle;
  ptr->printShapeInfo();
  std::cout << "Area= " << ptr->getArea() << "\n";
  ptr->move({ 5, 5 });
  std::cout << "After moving to {5,5}: " << "\n";
  ptr->printShapeInfo();
  ptr->move(2, 3);
  std::cout << "After moving on dx=2, dy=3" << "\n";
  ptr->printShapeInfo();
  printFrameInfo(ptr->getFrameRect());
  std::cout << "\n";

  Triangle oTriangle{ {0, 0}, {10, 10}, {20, 0} };
  ptr = &oTriangle;
  ptr->printShapeInfo();
  std::cout << "Area= " << ptr->getArea() << "\n";
  ptr->move({ 5, 5 });
  std::cout << "After moving to {5,5}: " << "\n";
  ptr->printShapeInfo();
  ptr->move(2, 3);
  std::cout << "After moving on dx=2, dy=3" << "\n";
  ptr->printShapeInfo();
  printFrameInfo(ptr->getFrameRect());
  std::cout << "\n";
 
  return 0;
}
