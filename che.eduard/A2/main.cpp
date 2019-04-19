#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void showInfo (Shape & shape1)
{
  std::cout << "height = " << shape1.getFrameRect().height << std::endl;
  std::cout << ", width = " << shape1.getFrameRect().width;
  std::cout << "point x = " << shape1.getFrameRect().pos.x;
  std::cout << ", point y = " << shape1.getFrameRect().pos.y; 
  std::cout << "Area = " << shape1.getArea() << std::endl;
}

int main()
{
  std::cout << "Circle:" << std::endl;
  che::Circle circle({1,1},3);
  showInfo(circle);
  std::cout << "Scaling by 2: " << std::endl;
  circle.scale(2);
  showInfo(circle);

  std::cout << "Rectangle:" << std::endl;
  che::Rectangle rectangle({2.0, 2.0}, 10.0, 10.0);
  showInfo(rectangle);
  std::cout << "Scaling by 1.5: " << std::endl;
  rectangle.scale(1.5);
  showInfo(rectangle);
  
  return 0;
}
