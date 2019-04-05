#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle circle1({1.0, 1.0}, 5.0);
  std::cout<<"Circle area "<<circle1.getArea()<<std::endl;

  Circle circle2({2.0, 2.0}, 2.0);
  circle2.move(1.0, 3.5);

  Shape *circleP = &circle1;
  rectangle_t coordinates = circleP->getFrameRect();
  std::cout<<"x "<<coordinates.pos.x<<" y "<<coordinates.pos.y<<std::endl;
  std::cout<<"Height "<<coordinates.height<<" Width "<<coordinates.width<<std::endl;

  Rectangle rectangle1({2.0, 2.0}, 5.0, 6.0);
  std::cout<<"Rectangle area "<<rectangle1.getArea()<<std::endl;
  rectangle1.move(3.0, 4.0);

  Rectangle rectangle2({5.0, 6.0}, 3.0, 1.0);
  std::cout<<"Rectangle #2 area "<<rectangle2.getArea()<<std::endl;

  Shape *rectP = &rectangle1;
  coordinates = rectP->getFrameRect();
  std::cout<<"x "<<coordinates.pos.x<<" y "<<coordinates.pos.y<<std::endl;
  std::cout<<"Width "<<coordinates.width<<" Height "<<coordinates.height<<std::endl;

  return 0;
}
