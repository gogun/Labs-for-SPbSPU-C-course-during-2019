#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
int main(void)
{
  //Circle test
  point_t cir_center={5.0,4.0};
  Circle cir1(cir_center, 7.0);
  cir1.getInfo();
  std::cout <<"Area of cir1:"<<cir1.getArea() << std::endl;
  std::cout <<"Height of FrameRect(cir1):"<<cir1.getFrameRect().height << std::endl;
  point_t b;
  b.x=10;
  b.y=23;
  cir1.move(b);
  std::cout <<"Moving to point b(cir1):"<< std::endl;
  cir1.getInfo();
  cir1.move(5,7);
  std::cout <<"Moving with increment(cir1):"<<std::endl;
  cir1.getInfo();
  std::cout <<"---------------------------------"<< std::endl;
  //Rectangle test
  point_t rect_center={43,100};
  Rectangle rect1(rect_center, 5, 3);
  rect1.getInfo();
  std::cout <<"Area of rect1: "<<rect1.getArea() << std::endl;
  std::cout <<"Height of FrameRect(rect1): "<<rect1.getFrameRect().height << std::endl;
  rect1.move(b);
  std::cout <<"Moving to point b(rect1): "<< std::endl;
  rect1.getInfo();
  rect1.move(5,24);
  std::cout <<"Moving with increment (rect1): " << std::endl;
  return 0;
}
