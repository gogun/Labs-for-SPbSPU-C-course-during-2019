#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

int main()
{
  Rectangle Rectangle{ 4, 6, 5, 5 };
  std::cout << "Get Area" << std::endl;
  Rectangle.getArea();
  std::cout << "Move by point" << std::endl;
  Rectangle.move(3, 7);
  std::cout << "Move by shift" << std::endl;
  Rectangle.move({ 3, 7 });
  Rectangle.getFrameRect();
  std::cout << "--------------------------" << std::endl;
  Circle Circle{ 4, 2, 5, 6 };
  std::cout << "Get Area" << std::endl;
  Circle.getArea();
  std::cout << "Move by point" << std::endl;
  Circle.move(3, 3);
  std::cout << "Move by shift" << std::endl;
  Circle.move({ 4, 5 });
  Circle.getFrameRect();
  return 0;
}
