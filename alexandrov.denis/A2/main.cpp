#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

using namespace alexandrov;

void showShapeDetails (Shape & shape1)
{
  std::cout << "Area:" << shape1.getArea() << std::endl;
  std::cout << "Frame rectangle: Ox = " << shape1.getFrameRect().pos.x;
  std::cout << ", Oy = " << shape1.getFrameRect().pos.y;
  std::cout << ", width = " << shape1.getFrameRect().width;
  std::cout << ", height = " << shape1.getFrameRect().height << std::endl;
}

int main()
{
  std::cout << "Circle:" << std::endl;
  Circle circle1({5, 5}, 2);
  showShapeDetails(circle1);
  circle1.scale(3);
  std::cout << "use scale(3):" << std::endl;
  showShapeDetails(circle1);
  std::cout << "\n\n";

  std::cout << "Rectangle:" << std::endl;
  Rectangle rectangle1({{0, 0}, 2, 2});
  showShapeDetails(rectangle1);
  rectangle1.scale(0.5);
  std::cout << "use scale(0.5):" << std::endl;
  showShapeDetails(rectangle1);
  return 0;
}
