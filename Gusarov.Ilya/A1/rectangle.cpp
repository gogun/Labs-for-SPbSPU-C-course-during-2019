#include <iostream>
#include "rectangle.hpp"
#include "shape.hpp"
#include "base-types.hpp"

int main()
{
  Rectangle newShape;
  Shape &rectangle = newShape;
  std::cout << "Enter width of rectangle: ";
  std::cin >> rectangle.data_of_rectangle.width;
  std::cout << "Enter height of rectangle: ";
  std::cin >> rectangle.data_of_rectangle.height;
  std::cout << "Area of rectangle: " << rectangle.getArea(rectangle.data_of_rectangle) << '\n';

  rectangle.left_bottom.x = 1;
  rectangle.left_bottom.y = 5;

  rectangle.left_upper.x = 3;
  rectangle.left_upper.y = 7;

  rectangle.right_bottom.x = 5;
  rectangle.right_bottom.y = 1;

  rectangle.right_upper.x = 7;
  rectangle.right_upper.y = 3;
  
  std::cout << rectangle.getFrameArea().width << ' ' <<rectangle.getFrameArea().height << '\n';
  std::cout << rectangle.getFrameArea().pos.x << ' ' <<rectangle.getFrameArea().pos.y << '\n';
  return 0;
}
