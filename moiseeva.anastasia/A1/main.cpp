#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle c1({3.0, 1.0}, 5.0);
  std::cout<<"Circle area "<<c1.getArea()<<std::endl;

  Circle c2({1.0, 2.0}, 4.0);
  c2.move({3.0, 5.0});

  Shape *figureP = &c2;
  rectangle_t tempRect = figureP->getFrameRect();
  std::cout<<"X = "<<tempRect.pos.x<<" Y = "<<tempRect.pos.y<<std::endl;
  std::cout<<"Width = "<<tempRect.width<<" Height = "<<tempRect.height<<std::endl;
  figureP->move(1.0, 3.5);
  tempRect = figureP->getFrameRect();
  std::cout<<"X after moving "<<tempRect.pos.x<<" Y after moving "<<tempRect.pos.y<<std::endl;

  Rectangle r1({2.0, 2.0}, 5.0, 5.0);
  std::cout<<"Rectangle area "<<r1.getArea()<<std::endl;

  Rectangle r2({3.0, 3.0}, 7.0, 6.0);
  r2.move(1.0, 2.0);

  figureP = &r2;
  tempRect = figureP->getFrameRect();
  std::cout<<"X = "<<tempRect.pos.x<<" Y = "<<tempRect.pos.y<<std::endl;
  std::cout<<"Width = "<<tempRect.width<<" Height = "<<tempRect.height<<std::endl;
  figureP->move(1.0, 3.5);
  tempRect = figureP->getFrameRect();
  std::cout<<"X after moving "<< tempRect.pos.x<<" Y after moving "<<tempRect.pos.y<<std::endl;

  return 0;
}
