#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle circle({ 3,4 }, 6);
  circle.getInfo();
  std::cout << "The area of circle is: " << circle.getArea() << std::endl;
  std::cout << "Width of frame rectangle is: " << circle.getFrameRect().width << std::endl;
  std::cout << "Height of frame rectangle is: " << circle.getFrameRect().height << std::endl;
  circle.move({ 1,1 });
  circle.getInfo();
  circle.move(4, 5);
  circle.getInfo();
  Rectangle rectangle({ 5,5 }, 20, 5);
  rectangle.getInfo();
  std::cout << "The area of rectangle is: " << rectangle.getArea() << std::endl;
  std::cout << "Width of frame rectangle is: " << rectangle.getFrameRect().width << std::endl;
  std::cout << "Height of frame rectangle is: " << rectangle.getFrameRect().height << std::endl;
  rectangle.move({ 6,4 });
  rectangle.getInfo();
  rectangle.move(-1, 1);
  rectangle.getInfo();
  return 0;
}