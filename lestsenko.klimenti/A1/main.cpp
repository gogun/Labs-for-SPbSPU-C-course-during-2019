#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle1(5, { 1, 2 });

  Shape *figure = &circle1;

  std::cout << "Circle1 first pos: " << figure->getPos().x << "," << figure->getPos().y
      << "\nCircle1 area: " << figure->getArea();
  
  rectangle_t temp_rect = figure->getFrameRect();
  std::cout << "\nRectangle surrounding Circle1: h: " << temp_rect.height
      << ", w: " << temp_rect.width
      << ", x: " << temp_rect.pos.x
      << ", y: " << temp_rect.pos.y;

  figure->move({ 3,4 }); 
  std::cout << "\nCircle1 second pos: " << figure->getPos().x << ", " << figure->getPos().y;

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
