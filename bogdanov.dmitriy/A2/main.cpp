#include <iostream>

#include "common/shape.hpp"
#include "common/circle.hpp"
#include "common/rectangle.hpp"

void printInfo(const bogdanov::Shape &shape)
{
  shape.writeInfo();
}

int main()
{
  bogdanov::point_t pointCenter = {1.0, 1.0};
  bogdanov::Circle circle(pointCenter, 10.0);
  bogdanov::Rectangle rectangle(pointCenter, 20.0, 30.0);
  double scaleFactor = 4.0;
  printInfo(circle);
  printInfo(rectangle);

  std::cout << "Circle: Center(1.0, 1.0) move (2.0,2.0) -> center(3.0,3.0)" << std::endl;
  circle.move(2.0, 2.0);
  std::cout << "Circle radius(10.0) do increase in " << scaleFactor << "-> radius (30.0)" << std::endl;
  circle.scale(scaleFactor);
  printInfo(circle);
  std::cout << "Rectangle: Center(1.0, 1.0), move (4.0,4.0) -> center(5.0,5.0)" << std::endl;
  rectangle.move(4.0, 4.0);
  std::cout << "Rectangle width(20.0) and height(30.0) do increase in " << scaleFactor << "-> width(60.0) and height(90.0)" << std::endl;
  rectangle.scale(scaleFactor);
  printInfo(rectangle);

  scaleFactor = 1 / scaleFactor;
  std::cout << "Rectangle and Circle -> new center(2.0,2.0)" << std::endl;
  pointCenter = {2.0, 2.0};
  circle.move(pointCenter);
  rectangle.move(pointCenter);
  std::cout << "Circle radius(30.0) do increase in " << scaleFactor << "-> radius (10.0)" << std::endl;
  circle.scale(scaleFactor);
  std::cout << "Rectangle width(60.0) and height(90.0) do increase in " << scaleFactor << "-> width(20.0) and height(30.0)" << std::endl;
  rectangle.scale(scaleFactor);
  printInfo(circle);
  printInfo(rectangle);

  return 0;
}
