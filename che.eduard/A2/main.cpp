#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

using namespace che;

void showInfo (Shape & shape1)
{
  std::cout << "height = " << shape1.getFrameRect().height;
  std::cout << ", width = " << shape1.getFrameRect().width;
  std::cout << "point x = " << shape1.getFrameRect().pos.x;
  std::cout << ", point y = " << shape1.getFrameRect().pos.y; 
  std::cout << "Area = " << shape1.getArea() << std::endl;
  std::cout << "\n\n" << std::endl;
}

int main()
{
  std::cout << "Circle:" << std::endl;
  Circle circle1({1,1},3);
  showInfo(circle1);
  std::cout << "Scaling by 2: " << std::endl;
  circle1.scale(2);
  showInfo(circle1);

  std::cout << "Rectangle:" << std::endl;
  Rectangle rectangle1({2,2,{10,10}});
  showInfo(rectangle1);
  std::cout << "Scaling by 1.5: " << std::endl;
  circle1.scale(1.5);
  showInfo(rectangle1);
  
  return 0;
}
