#include "circle.hpp"
#include "rectangle.hpp"
#include <iostream>

int main()
{
  point_t myPoint = { 2, 3 };
  std::cout << "mypoint " << "( " << myPoint.x << "," << myPoint.y << ")" << '\n';
  std::cout << '\n';

  Circle myCircle(2, myPoint);
  Shape *ptr_shape = &myCircle;
  ptr_shape->print();
  std::cout << "circle area " << myCircle.getArea() <<std:: endl;
  ptr_shape->move(1, 2);
  std::cout <<'\n';
  std::cout << "move the circle with (1,2)"<<std:: endl;
  std::cout <<'\n';
  std::cout << "frame rect.x= "<<myCircle.getFrameRect().pos.x <<std:: endl;
  std::cout << "frame rect.y= "<<myCircle.getFrameRect().pos.y <<std:: endl;
  ptr_shape->move(myPoint);
  std::cout << '\n';
  Rectangle myRect(3, 4, { 2, 2 });
  ptr_shape = &myRect;
  ptr_shape->print();
  ptr_shape->move(3, 4);
  std::cout << '\n';
  std::cout << "move the rectangle with (3,4)"<< std:: endl;
  std::cout << '\n';
  ptr_shape->print();
  std::cout << "rectangle area = "<<myRect.getArea()<<std::endl;
  std::cout << '\n';
  return 0;
  }
  
