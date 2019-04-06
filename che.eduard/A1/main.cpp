#include "circle.hpp"
#include "rectangle.hpp"
#include <iostream>

void showShapeWork (Shape & shape1)
{
  std::cout << "Area:" << shape1.getArea() << std::endl;
  std::cout << "Frame : Ox = " << shape1.getFrameRect().pos.x;
  std::cout << ", Oy = " << shape1.getFrameRect().pos.y;
  std::cout << ", height = " << shape1.getFrameRect().height;
  std::cout << ", width = " << shape1.getFrameRect().width << std::endl;
  std::cout << "Moving to new position: Ox = 0; Oy = 0; " << std::endl;
  shape1.move({ 0, 0 });
  std::cout << "Ox = " << shape1.getFrameRect().pos.x;
  std::cout << ", Oy = " << shape1.getFrameRect().pos.y << std::endl;
  std::cout << "Moving to the new point: Ox + 5; Oy + 10;" << std::endl;
  shape1.move(5, 10);
  std::cout << "Ox = " << shape1.getFrameRect().pos.x;
  std::cout << ", Oy = " << shape1.getFrameRect().pos.y << std::endl;
}

int main()
{
  std::cout << "Circle:" << std::endl;
  Circle circle1({0,0},3);
  showShapeWork(circle1);
  std::cout << "Rectangle:" << std::endl;

  Rectangle rectangle1({2,2,{10,10}});
  showShapeWork(rectangle1);
  system("pause>NULL");
  return 0;
}
