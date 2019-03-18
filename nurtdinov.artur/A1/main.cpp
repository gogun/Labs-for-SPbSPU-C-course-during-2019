#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  //Rectangle
  Rectangle rectangle({5, 5}, 10, 5);
  point_t pos = rectangle.getPosition();
  std::cout << "Position of rectangle: x = " << pos.x << ", y = " << pos.y << "\n";
  rectangle.move({15, 50});
  pos = rectangle.getPosition();
  std::cout << "New position of rectangle: x = " << pos.x << ", y = " << pos.y << "\n";
  rectangle.move(25, 10); // x = 15 + 25 = 40, y = 50 + 10 = 60
  pos = rectangle.getPosition();
  std::cout << "New position of rectangle: x = " << pos.x << ", y = " << pos.y << "\n";
  double areaOfRectangle = rectangle.getArea(); // 10 * 5 = 50;
  std::cout << "Area of this rectangle is " << areaOfRectangle << "\n";
  rectangle_t frameRect = rectangle.getFrameRect(); // width = 10, height = 5, pos = 40, 60
  std::cout << "Width of frame = " << frameRect.width << ", height = " << frameRect.height << "\n";
  std::cout << "Position of frame: x = " << frameRect.pos.x << ", y = " << frameRect.pos.y << "\n\n";

  //Circle
  Circle circle({0, 0}, 5);
  pos = circle.getPosition();
  std::cout << "Position of circle: x = " << pos.x << ", y = " << pos.y << "\n";
  circle.move({5, 5});
  pos = circle.getPosition();
  std::cout << "New position of circle: x = " << pos.x << ", y = " << pos.y << "\n";
  circle.move(25, 10); // x = 5 + 25 = 30, y = 5 + 10 = 15;
  pos = circle.getPosition();
  std::cout << "New position of circle: x = " << pos.x << ", y = " << pos.y << "\n";
  double areaOfCircle = circle.getArea(); // 5 * 5 = 25;
  std::cout << "Area of this circle is " << areaOfCircle << "\n";
  frameRect = circle.getFrameRect(); // width = 10, height = 10, pos = 30, 15
  std::cout << "Width of frame = " << frameRect.width << ", height = " << frameRect.height << "\n";
  std::cout << "Position of frame: x = " << frameRect.pos.x << ", y = " << frameRect.pos.y << "\n\n";
}


