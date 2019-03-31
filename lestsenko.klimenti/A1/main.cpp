#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle1(5, { 1, 2 });

  Shape *figure = &circle1;

  std::cout << "Circle1 first pos: " << figure->getPos().x << "," << figure->getPos().y
      << "\nCircle1 area: " << figure->getArea()
      << "\nRectangle surrounding Circle1: h: " << figure->getFrameRect().height
      << ", w: " << figure->getFrameRect().width
      << ", x: " << figure->getFrameRect().pos.x
      << ", y: " << figure->getFrameRect().pos.y;

  figure->move({ 3,4 }); figure->getPos().y;

  figure->move(5, 6);
  std::cout << "\nCircle1 third pos: " << figure->getPos().x << ", " << figure->getPos().y;

  Rectangle rectangle1(3, 4, { 5,6 });

  figure = &rectangle1;
  
  std::cout << "\n\nRectangle1 first pos: " << figure->getPos().x << ", " << figure->getPos().y
      << "\nRectangle1 area: " << figure->getArea();

  figure->move({ 3,4 });
  std::cout << "\nRectangle1 second pos: " << figure->getPos().x << ", " << figure->getPos().y;

  figure->move(5, 6);
  std::cout << "\nRectangle1 third pos: " << figure->getPos().x << ", " << figure->getPos().y << std::endl;
  
  return 0;
}
