#include <iostream>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

int main()
{
  double dx = 10;
  double dy = 20;
  point_t xpoint;
  xpoint.x = 333;
  xpoint.y = 555;
  Rectangle MyRectangle(100, 200, 123, 57);
  Circle MyCircle(111, 222, 45);
  Rectangle OgRectangle;
  MyRectangle.show();
  MyCircle.show();
  std::cout << "Rectangle area = " << MyRectangle.getArea() << std::endl;
  std::cout << "Circle area =  " << MyCircle.getArea() << std::endl;
  
  OgRectangle = MyRectangle.getFrameRect();
  std::cout << "Rectangle border:" << std::endl;
  OgRectangle.show();
  
  OgRectangle = MyCircle.getFrameRect();
  std::cout << "Circle border:\n" << std::endl;
  OgRectangle.show();
  
  MyRectangle.move(dx, dy);
  std::cout << "Move" << std::endl;
  MyRectangle.show();
  
  MyCircle.move(dx, dy);
  std::cout << "Move\n" << std::endl;
  MyCircle.show();
  
  MyRectangle.move(xpoint);
  std::cout << "Move\n" << std::endl;
  MyRectangle.show();
  
  MyCircle.move(xpoint);
  std::cout << "Move\n" << std::endl;
  MyCircle.show();
  
<<<<<<< HEAD
=======
  //system("pause");
>>>>>>> 21efff2bf96f287fe3008cc78e0d089cb8fec88f
  return 0;
}

