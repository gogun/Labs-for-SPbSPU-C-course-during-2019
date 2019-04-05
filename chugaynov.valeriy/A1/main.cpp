#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printRecData(const rectangle_t &rect)
{
  std::cout << "width = " << rect.width << "\theight = " << rect.height
    << "\tpos = (" << rect.pos.x << ", " << rect.pos.y << ")" << std::endl;
}

int main()
{
  point_t pointTest1{ 16.45, 18.4 };
  point_t pointTest2{ 363.5, 478.7 };

  Rectangle rect(12, 23.4, pointTest1);
  std::cout << "S = " << rect.getArea() << std::endl;
  rect.move(5, -4);
  printRecData(rect.getFrameRect());
  rect.move(pointTest2);
  printRecData(rect.getFrameRect());

  Circle circ(5.54, pointTest1);
  std::cout <<  "\nS = " << circ.getArea() << std::endl;
  circ.move(5.9, -3.5);
  printRecData(circ.getFrameRect());
  circ.move(pointTest2);
  printRecData(circ.getFrameRect());

  std::cout << "\n\npolymorphism:" << std::endl;

  Shape *shape = &rect;
  std::cout << "S = " << shape->getArea() << std::endl;
  shape->move(75.4, -4.18);
  printRecData(shape->getFrameRect());
  shape->move(pointTest1);
  printRecData(shape->getFrameRect());

  shape = &circ;
  std::cout << "\nS = " << shape->getArea() << std::endl;
  shape->move(0.3, -25.5);
  printRecData(shape->getFrameRect());
  shape->move(pointTest1);
  printRecData(shape->getFrameRect());

  return 0;
}
