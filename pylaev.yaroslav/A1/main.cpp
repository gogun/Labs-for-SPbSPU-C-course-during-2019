#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main(int, char *[])
{
  const double dx = 3.5;
  const double dy = 5.5;
  const point_t newPoint = {10.0, 10.0};

  //Rectangle
  std::cout << "----------Work with the rectangle\n";
  point_t center = {1.0, 8.0};
  Rectangle rectangle_(center, 5.0, 9.0);
  Shape *shapePtr = &rectangle_;
  shapePtr->printSpec();
  shapePtr->move(dx, dy); //move by delta
  std::cout << " After moving by " << dx << "; " << dy << std::endl;
  shapePtr->printSpec();
  shapePtr->move(newPoint); //move to the point
  std::cout << " After moving to the point (" << newPoint.x << "; "
    << newPoint.y << ")\n";
  shapePtr->printSpec();

  std::cout << std::endl;
  //Circle
  std::cout << "----------Work with the circle\n";
  center = {10.0, 80.0};
  Circle circle_(center, 18.0);
  shapePtr = &circle_;
  shapePtr->printSpec();
  shapePtr->move(dx, dy);
  std::cout << " After moving by " << dx << "; " << dy << std::endl;
  shapePtr->printSpec();
  shapePtr->move(newPoint);
  std::cout << " After moving to the point (" << newPoint.x << "; "
    << newPoint.y << ")\n";
  shapePtr->printSpec();

  return 0;
}
