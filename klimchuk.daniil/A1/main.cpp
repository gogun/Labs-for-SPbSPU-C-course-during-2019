#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main(int, char *[])
{
  Rectangle rectangle = {5.0, 3.5, {-1.0, -2.0}};
  Circle circle = {2.5, {3.14, 2.71}};

  std::cout << "That's what we have:" << std::endl;
  rectangle.printInfo();
  circle.printInfo();

  std::cout << "Let's move the shapes 2 units left and 7.77 units up." << std::endl;
  rectangle.move(-2.0, 7.77);
  rectangle.printInfo();
  circle.move(-2.0, 7.77);
  circle.printInfo();

  std::cout << "Now we will move the shapes to a specific point (3, 4)." << std::endl;
  rectangle.move({3.0, 4.0});
  rectangle.printInfo();
  circle.move({3.0, 4.0});
  circle.printInfo();


  rectangle_t rectangleFrame = rectangle.getFrameRect();
  std::cout << "Frame rectangle for the rectangle:"
            << std::endl << "  Width: " << rectangleFrame.width
            << std::endl << "  Height: " << rectangleFrame.height
            << std::endl << "  Position: "
            << std::endl << "    x: " << rectangleFrame.pos.x
            << std::endl << "    y: " << rectangleFrame.pos.y
            << std::endl << std::endl;

  rectangle_t circleFrame = circle.getFrameRect();
  std::cout << "Frame rectangle for the circle:"
            << std::endl << "  Width: " << circleFrame.width
            << std::endl << "  Height: " << circleFrame.height
            << std::endl << "  Position: "
            << std::endl << "    x: " << circleFrame.pos.x
            << std::endl << "    y: " << circleFrame.pos.y
            << std::endl << std::endl;

  return 0;
}
