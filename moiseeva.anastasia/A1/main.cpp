#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle r1({2.0, 2.0}, 5.0, 5.0);
  std::cout<<"Rectangle area "<<r1.getArea()<<std::endl;

  Rectangle r2({3.0, 3.0}, 7.0, 6.0);
  r2.move(1.0, 2.0);

  Circle c1({3.0, 1.0}, 5.0);
  std::cout<<"Circle area "<<c1.getArea()<<std::endl;

  Circle c2({1.0, 2.0}, 4.0);
  c2.move({3.0, 5.0});

  Shape *circP = &c2;
  rectangle_t tempRect = circP->getFrameRect();
  std::cout<<"X = "<<tempRect.pos.x<<" Y = "<<tempRect.pos.y<<std::endl;
  std::cout<<"Width = "<<tempRect.width<<" Height = "<<tempRect.height<<std::endl;

  Shape *rectP = &r2;
  tempRect = rectP->getFrameRect();
  std::cout<<"X = "<<tempRect.pos.x<<" Y = "<<tempRect.pos.y<<std::endl;
  std::cout<<"Width = "<<tempRect.width<<" Height = "<<tempRect.height<<std::endl;

  return 0;
}
