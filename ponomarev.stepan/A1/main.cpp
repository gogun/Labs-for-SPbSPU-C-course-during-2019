#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main() {
  Rectangle r1({1.0,1.0}, 3.0, 3.0);
  std::cout<<r1.getArea()<<std::endl;

  Rectangle r2({2.0,2.0}, 1.0, 4.0);
  r2.move(1.0,2.0);

  Circle c1({3.0,1.0}, 3.0);
  std::cout<<c1.getArea()<<std::endl;

  Circle c2({1.0,2.0}, 4.0);
  c2.move({3.0,5.0});

  Shape *circP = &c2;
  rectangle_t tempRect = circP->getFrameRect();
  std::cout<<tempRect.pos.x<<" "<<tempRect.pos.y<<" "<<tempRect.width<<" "<<tempRect.height<<std::endl;

  Shape *rectP = &r2;
  tempRect = rectP->getFrameRect();
  std::cout<<tempRect.pos.x<<" "<<tempRect.pos.y<<" "<<tempRect.width<<" "<<tempRect.height<<std::endl;

  return 0;
}
