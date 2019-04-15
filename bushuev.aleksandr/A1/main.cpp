#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{

  std::cout << "--------------------Rectangle---------------------" << std::endl;

  Rectangle rectTest({25, -11}, 10, 8);
  Shape* testShape = &rectTest;

  rectangle_t frame = testShape->getFrameRect();
  std::cout << "Frame at:" << "(" << frame.pos.x << "," << frame.pos.y << ")" << std::endl;
  std::cout << "Width: " << frame.width << "," << "height: " << frame.height << std::endl;

  std::cout << "Rectangle moved on:" << "(" << 11 << "," << 15 << ")" << std::endl;
  testShape->move(11, 15);
  testShape->printInfo();

  std::cout << "Rectangle moved to:" << "(" << 11.11 << "," << 11.13 << ")" << std::endl;
  testShape->move({11.11, 11.13});
  testShape->printInfo();

  std::cout << "--------------------------------------------------" << std::endl;

  std::cout << "--------------------Circle------------------------" << std::endl;

  Circle circleTest({10, 10}, 10);
  testShape = &circleTest;
  testShape->printInfo();

  frame = testShape->getFrameRect();
  std::cout << "Frame at:" << "(" << frame.pos.x << "," << frame.pos.y << ")" << std::endl;
  std::cout << "Width: " << frame.width << "," << "height: " << frame.height << std::endl;

  std::cout << "Circle moved on:" << "(" << 0 << "," << -15 << ")" << std::endl;
  testShape->move(0, -15);
  testShape->printInfo();

  std::cout << "Circle moved to:" << "(" << 224.14 << "," << -15.7 << ")" << std::endl;
  testShape->move({224.14, -15.7});
  testShape->printInfo();

  std::cout << "--------------------------------------------------" << std::endl;

  std::cout << "--------------------Triangle------------------------" << std::endl;
  
  Triangle triangleTest({0, 0}, 25.11, 11.14, 20.01);
  testShape = &triangleTest;
  testShape->printInfo();

  frame = testShape->getFrameRect();
  std::cout << "Frame at:" << "(" << frame.pos.x << "," << frame.pos.y << ")" << std::endl;
  std::cout << "Width: " << frame.width << "," << "height: " << frame.height << std::endl;

  std::cout << "Triangle moved on:" << "(" << 0 << "," << -15 << ")" << std::endl;
  testShape->move(0, -15);
  testShape->printInfo();

  std::cout << "Triangle moved to:" << "(" << 224.14 << "," << -15.7 << ")" << std::endl;
  testShape->move({224.14, -15.7});
  testShape->printInfo();
  
  return 0;
}
