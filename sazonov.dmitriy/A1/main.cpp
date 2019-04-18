#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle1(7, { 4, 5 });

  Shape *figure = &circle1;

  std::cout << "Circle1 first position: " << figure->getPos().x << ", " << figure->getPos().y
      << "\n " << "Circle1 area: " << figure->getArea();

  rectangle_t temp_rect = figure->getFrameRect();
  std::cout << "\n " << "Rectangle surrounding Circle1: h: " << temp_rect.height
      << ", width: " << temp_rect.width
      << ", x: " << temp_rect.pos.x
      << ", y: " << temp_rect.pos.y << "\n ";

  figure->move({ 11,12 });
  std::cout << "Circle1 second position: " << figure->getPos().x << ", " << figure->getPos().y << "\n ";

  figure->move(5, 6);
  std::cout << "Circle1 third position: " << figure->getPos().x << ", " << figure->getPos().y << "\n";

  Rectangle rectangle1(11, 12, { 5,6 });

  figure = &rectangle1;

  std::cout << "\n " << "Rectangle1 first position: " << figure->getPos().x << ", " << figure->getPos().y
      << "\n " << "Rectangle1 area: " << figure->getArea() << "\n ";

  figure->move({ 11,12 });
  std::cout << "Rectangle1 second position: " << figure->getPos().x << ", " << figure->getPos().y << "\n";

  figure->move(5, 6);
  std::cout << "Rectangle1 third position: " << figure->getPos().x << ", " << figure->getPos().y;

  return 0;
}
