#include "Circle.hpp"
#include "Rectangle.hpp"
#include <iostream>

int main()
{
  point_t myPoint = { 2, 3 };
  std::cout <<"mypoint "<< "( "<<myPoint.x << ","<< myPoint.y << ")"<<std:: endl;
  std::cout << '\n';
  Circle myCircle(2, myPoint);
  myCircle.print();

  std::cout << "circle area " << myCircle.getArea() <<std:: endl;
  myCircle.move(1, 2);

  std::cout <<"\n";
  std::cout << "move the circle with (1,2)"<<std:: endl;
  std::cout <<"\n";
  std::cout << "frame rect.x= "<<myCircle.getFrameRect().pos.x <<std:: endl;
  std::cout << "frame rect.y= "<<myCircle.getFrameRect().pos.y <<std:: endl;
  myCircle.move(myPoint);

  std::cout << '\n';
  Rectangle myRect(3, 4, { 2, 2 });
  myRect.print();
  
  myRect.move(3, 4);

  std::cout << '\n';
  std::cout << "move the rectangle with (3,4)"<< std:: endl;
  std::cout << "\n";
  myRect.print();

  std::cout << "rectangle area = "<<myRect.getArea()<<std::endl;
  std::cout << '\n';
  return 0;
	}

  
  