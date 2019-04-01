#include "circle.hpp"
#include "rectangle.hpp"
#include <iostream>

void showShapeWork (Shape & shape1)
{
  std::cout << "Area:" << shape1.getArea() << std::endl;
  std::cout << "Frame rectangle: Ox = " << shape1.getFrameRect().pos.x
    << ", Oy = " << shape1.getFrameRect().pos.y
    << ", height = " << shape1.getFrameRect().height
    << ", width = " << shape1.getFrameRect().width << std::endl;
  shape1.move({0, 0});
  std::cout << "Moved to new Point(0, 0)" << std::endl;
  std::cout << "Ox = " << shape1.getFrameRect().pos.x
    << ", Oy = " << shape1.getFrameRect().pos.y << std::endl;
  shape1.move(10, 20);
  std::cout << "Axis offset: Ox + 10, Oy + 20" << std::endl;
  std::cout << "Ox = " << shape1.getFrameRect().pos.x
    << ", Oy = " << shape1.getFrameRect().pos.y << std::endl;
}

int main()
{
  std::cout << "Circle:" << std::endl;
  Circle circle1({5,5},2);
  showShapeWork(circle1);
  std::cout << "Rectangle:" << std::endl;
  Rectangle rectangle1({3,3,{1,1}});
  showShapeWork(rectangle1);

  return 0;
}
