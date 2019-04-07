#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectan({5,4,{1,5}});
  Shape * shapeptr = &rectan;
  std::cout << "-----Making a rectangle-----\n";
  shapeptr->printInformation();
  std::cout << "-----Moving the rectangle-----\n";
  std::cout << "+++++Moving to the point (3,4)+++++\n";
  shapeptr->move({3,4});
  shapeptr->printInformation();
  std::cout << "+++++Moving along abscissa for 1 and along ordinate for 2+++++\n";
  shapeptr->move(1,2);
  shapeptr->printInformation();
  std::cout << "-----Rectangle is done-----\n";
  std::cout << '\n';

  Circle circle({6,{10,10}});
  shapeptr = &circle;
  std::cout << "-----Making a circle-----\n";
  shapeptr->printInformation();
  std::cout << "-----Moving the circle-----\n";
  std::cout << "+++++Moving to the point (3,4)+++++\n";
  shapeptr->move({5,9});
  shapeptr->printInformation();
  std::cout << "+++++Moving along abscissa for 1 and along ordinate for -6+++++\n";
  shapeptr->move(1,-6);
  shapeptr->printInformation();
  std::cout << "-----Circle is done-----\n";
  return 0;
}
