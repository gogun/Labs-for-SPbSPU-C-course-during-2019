#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

void getInfo(const Shape *figure)
{
  assert(figure != nullptr);
  figure->getInfo();
}

int main()
{
  Circle circle1({0,0}, 5);
  circle1.move({2,2});
  circle1.move(3,7.7);
  getInfo(&circle1);
  std::cout << "Circle Area is: " << circle1.getArea() << std::endl;
  std::cout << "Rect around Circle: \n";
  std::cout << "X: " << circle1.getFrameRect().pos.x << std::endl;
  std::cout << "Y: " << circle1.getFrameRect().pos.y << std::endl;
  std::cout << "Width: " << circle1.getFrameRect().width << " Height: " << circle1.getFrameRect().height;
  std::cout << "\n";

  Rectangle rec1({2.2,3.5}, 3, 6);
  rec1.move({0,0});
  rec1.move(5, 4);
  getInfo(&rec1);
  std::cout << "Rectangle Area is: " << rec1.getArea() << std::endl;
  return 0;
}
