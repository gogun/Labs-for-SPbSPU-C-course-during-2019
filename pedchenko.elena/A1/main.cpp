#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"


void showInfo(const Shape &shape)
{
  shape.writeInfo();
}


int main()
{
  point_t pointCenter = {1.0, 1.0};
  Circle circle(pointCenter, 10.0);
  Rectangle rectangle(pointCenter, 20.0, 30.0);
  showInfo(circle);
  showInfo(rectangle);

  std::cout << "For Circle. From center (1.0, 1.0) move (2.0,2.0) = center(3.0,3.0)" << std::endl;
  circle.move(2.0, 2.0);
  showInfo(circle);
  std::cout << "For Rectangle. From center(1.0, 1.0) move (4.0,4.0) = center(5.0,5.0)" << std::endl;
  rectangle.move(4.0, 4.0);
  showInfo(rectangle);

  std::cout << "For Rectangle and Circle -> new center (2.0,2.0)" << std::endl;
  pointCenter = {2.0, 2.0};
  circle.move(pointCenter);
  rectangle.move(pointCenter);
  showInfo(circle);
  showInfo(rectangle);

  return 0;
}
