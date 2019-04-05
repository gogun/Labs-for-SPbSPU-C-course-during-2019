#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{

  std::cout << "--------------------Rectangle---------------------" << std::endl;

  Rectangle rectTest({25,-11},10,8);
  rectTest.printInfo();

  rectangle_t frame = rectTest.getFrameRect();
  std::cout << "Frame at:" << "(" << frame.pos.x << "," << frame.pos.y << ")" << std::endl;
  std::cout << "Width: " << frame.width << ", " << "height: " << frame.height << std::endl;

  std::cout << "Rectangle moved on:" << "(" << 11 << "," << 15 << ")" << std::endl;
  rectTest.move(11,15);
  rectTest.printInfo();

  std::cout << "Rectangle moved to:" << "(" << 11.11 << "," << 11.13 << ")" << std::endl;
  rectTest.move({11.11,11.13});
  rectTest.printInfo();

  std::cout << "--------------------------------------------------" << std::endl;

  std::cout << "--------------------Circle------------------------" << std::endl;

  Circle circleTest({10,10},10);
  circleTest.printInfo();

  frame = circleTest.getFrameRect();
  std::cout << "Frame at:" << "(" <<frame.pos.x << "," << frame.pos.y << ")" << std::endl;
  std::cout << "Width: " << frame.width << ", " << "height: " << frame.height << std::endl;

  std::cout << "Circle moved on:" << "(" << 0 << "," << -15 << ")" << std::endl;
  circleTest.move(0,-15);
  circleTest.printInfo();

  std::cout << "Circle moved to:" << "(" << 224.14 << "," << -15.7 << ")" << std::endl;
  circleTest.move({224.14,-15.7});
  circleTest.printInfo();

  std::cout << "--------------------------------------------------" << std::endl;

  return 0;
}
