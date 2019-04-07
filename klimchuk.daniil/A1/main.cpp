#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main(int, char *[])
{
  Rectangle rectangle = {5.0, 3.5, {-1.0, -2.0}};
  Circle circle = {2.5, {3.14, 2.71}};

  std::cout << "That's what we have:\n";
  rectangle.printInfo();
  circle.printInfo();

  std::cout << "Let's move the shapes 2 units left and 7.77 units up.\n";
  rectangle.move(-2.0, 7.77);
  rectangle.printInfo();
  circle.move(-2.0, 7.77);
  circle.printInfo();

  std::cout << "Now we will move the shapes to a specific point (3, 4).\n";
  rectangle.move({3.0, 4.0});
  rectangle.printInfo();
  circle.move({3.0, 4.0});
  circle.printInfo();


  rectangle_t rectangleFrame = rectangle.getFrameRect();
  std::cout << "Frame rectangle for the rectangle:"
      << "\n  Width: " << rectangleFrame.width
        << "\n  Height: " << rectangleFrame.height
          << "\n  Position:"
            << "\n    x: " << rectangleFrame.pos.x
              << "\n    y: " << rectangleFrame.pos.y << "\n\n";

  rectangle_t circleFrame = circle.getFrameRect();
  std::cout << "Frame rectangle for the circle:"
      << "\n  Width: " << circleFrame.width
        << "\n  Height: " << circleFrame.height
          << "\n  Position:"
            << "\n    x: " << circleFrame.pos.x
              << "\n    y: " << circleFrame.pos.y << "\n\n";

  return 0;
}
