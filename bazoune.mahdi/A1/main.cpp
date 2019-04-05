#include "Circle.hpp"
#include "Rectangle.hpp"
#include <iostream>

int main()
{
  point_t myPoint = { 2, 3 };
  std::cout << "mypoint " << "( " << myPoint.x << "," << myPoint.y << ")" << '\n';
  std::cout << '\n';

  Circle myCircle(2, myPoint);
  myCircle -> print();
  std::cout << "circle area " << myCircle.getArea() << '\n';
  myCircle -> move(1, 2);
  std::cout <<'\n';
  std::cout << "move the circle with (1, 2)" << '\n';
  std::cout << '\n';
  std::cout << "frame rect.x= " << myCircle.getFrameRect().pos.x << '\n';
  std::cout << "frame rect.y= " << myCircle.getFrameRect().pos.y << '\n';
  myCircle -> move(myPoint);
  std::cout << '\n';

  Rectangle myRect(3, 4, { 2, 2 });
  myRect -> print();
  myRect -> move(3, 4);
  std::cout << '\n';
  std::cout << "move the rectangle with (3,4)"« '\n';
  std::cout << '\n';
  myRect -> print();
  std::cout << "rectangle area = " << myRect.getArea() << '\n';
  std::cout << '\n';

  return 0;
}
