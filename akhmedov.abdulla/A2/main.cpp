#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

void getInfo(const akhmedov::Shape * figure)
{
  if (figure == nullptr)
  {
    throw std::invalid_argument("Null pointer");
  }
  figure->printInfo();
}

int main()
{
  akhmedov::point_t centerPoint { 0 , 0 };

  akhmedov::Circle circle1(centerPoint, 5);
  circle1.move({ 2, 2 });
  circle1.move(3, 7.7);
  getInfo(&circle1);
  std::cout << "Circle Area is: " << circle1.getArea() << std::endl;
  std::cout << "Rect around Circle: \n";
  std::cout << "X: " << circle1.getFrameRect().pos.x << std::endl;
  std::cout << "Y: " << circle1.getFrameRect().pos.y << std::endl;
  std::cout << "Width: " << circle1.getFrameRect().width << " Height: " << circle1.getFrameRect().height;
  std::cout << "\n";
  circle1.scale(8);
  getInfo(&circle1);
  std::cout << "\n";

  akhmedov::Rectangle rectangle1(centerPoint, 3, 6);
  rectangle1.move({ 2.1, 3.6 });
  rectangle1.move(5, 4);
  getInfo(&rectangle1);
  std::cout << "Rectangle Area is: " << rectangle1.getArea() << std::endl;
  rectangle1.scale(5.6);
  getInfo(&rectangle1);
  std::cout << "Rectangle Area after scaling is: " << rectangle1.getArea() << std::endl;
  return 0;
}
