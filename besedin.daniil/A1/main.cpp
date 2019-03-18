#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{

  point_t point1 = {5, 5};
  Rectangle rectangle(3, 3, point1);
  Circle circle(7, point1);

  std::cout << "Rectangle" << std::endl;
  std::cout << "Width: " << rectangle.getFrameRect().width << '\t';
  std::cout << "Height: " << rectangle.getFrameRect().height << '\t';
  std::cout << "Center: ( " << rectangle.getFrameRect().pos.x << " , " << rectangle.getFrameRect().pos.y << " )";
  std::cout << std::endl;
  std::cout << "Area: " << rectangle.getArea() << std::endl;
  rectangle.move(3, 3);
  std::cout << "Center: ( " << rectangle.getFrameRect().pos.x << " , " << rectangle.getFrameRect().pos.y << " )";
  std::cout << '\n' << '\n';

  std::cout << "Circle" << std::endl;
  std::cout << "Width: " << circle.getFrameRect().width << '\t';
  std::cout << "Height: " << circle.getFrameRect().height << '\t';
  std::cout << "Center: ( " << circle.getFrameRect().pos.x << " , " << circle.getFrameRect().pos.y << " )";
  std::cout << std::endl;
  std::cout << "Area: " << circle.getArea() << std::endl;
  point_t point2 = {15, 15};
  circle.move(point2);
  std::cout << "Center: ( " << circle.getFrameRect().pos.x << " , " << circle.getFrameRect().pos.y << " )";
  std::cout << std::endl;

  return 0;

}