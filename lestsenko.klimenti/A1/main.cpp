#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle1(5, { 1, 2 });

  std::cout << "Circle1 first pos: " << circle1.getPos().x << "," << circle1.getPos().y
      << "\nCircle1 area: " << circle1.getArea()
      << "\nRectangle surrounding Circle1: h: " << circle1.getFrameRect().height
      << ", w: " << circle1.getFrameRect().width
      << ", x: " << circle1.getFrameRect().pos.x
      << ", y: " << circle1.getFrameRect().pos.y;

  circle1.move({ 3,4 });
  
  std::cout << "\nCircle1 second pos: " << circle1.getPos().x << ", " << circle1.getPos().y;

  circle1.move(5, 6);
  
  std::cout << "\nCircle1 third pos: " << circle1.getPos().x << ", " << circle1.getPos().y;

  Rectangle rectangle1(3, 4, { 5,6 });

  std::cout << "\n\nRectangle1 first pos: " << rectangle1.getPos().x << ", " << rectangle1.getPos().y
      << "\nRectangle1 area: " << rectangle1.getArea();

  rectangle1.move({ 3,4 });
  
  std::cout << "\nRectangle1 second pos: " << rectangle1.getPos().x << ", " << rectangle1.getPos().y;

  rectangle1.move(5, 6);
  
  std::cout << "\nRectangle1 third pos: " << rectangle1.getPos().x << ", " << rectangle1.getPos().y << std::endl;
  
  return 0;
}