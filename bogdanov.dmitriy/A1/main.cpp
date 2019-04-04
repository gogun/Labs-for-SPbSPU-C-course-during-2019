#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"

void printInfo(const Shape &shape)
{
  shape.writeInfo();
}

int main()
{
  point_t pointCenter = {1.0, 1.0};
  Circle circle(pointCenter, 10.0);
  Rectangle rectangle(pointCenter, 20.0, 30.0);
  printInfo(circle);
  printInfo(rectangle);

  std::cout << "Circle: Center(1.0, 1.0) move (2.0,2.0) -> center(3.0,3.0)" << std::endl;
  circle.move(2.0, 2.0);
  printInfo(circle);
  std::cout << "Rectangle: Center(1.0, 1.0), move (4.0,4.0) -> center(5.0,5.0)" << std::endl;
  rectangle.move(4.0, 4.0);
  printInfo(rectangle);

  std::cout << "Rectangle and Circle -> new center(2.0,2.0)" << std::endl;
  pointCenter = {2.0, 2.0};
  circle.move(pointCenter);
  rectangle.move(pointCenter);
  printInfo(circle);
  printInfo(rectangle);

  return 0;
}
