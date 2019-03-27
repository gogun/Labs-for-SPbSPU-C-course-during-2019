#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t movePoint = {224,11.11};

  std::cout << "--------------------Rectangle---------------------" << std::endl;

  Rectangle rect(15,15,15,15);
  rect.coutInfo();

  rectangle_t frame = rect.getFrameRect();
  std::cout << "Frame at:" << "("<<frame.pos.x << "," << frame.pos.y << ")" << std::endl;
  std::cout << "Width: " << frame.width << ", " << "height: " << frame.height << std::endl;

  std::cout << "Rectangle moved on:" << "("<< 11 << "," << 15 << ")" << std::endl;
  rect.move(11,15);
  rect.coutInfo();

  std::cout << "Rectangle moved to:" << "("<< movePoint.x << "," << movePoint.y << ")" << std::endl;
  rect.move(movePoint);
  rect.coutInfo();

  std::cout << "--------------------------------------------------" << std::endl;

  std::cout << "--------------------Circle------------------------" << std::endl;

  Circle circleTest(10,10,10);
  circleTest.coutInfo();

  frame = circleTest.getFrameRect();
  std::cout << "Frame at:" << "("<<frame.pos.x << "," << frame.pos.y << ")" << std::endl;
  std::cout << "Width: " << frame.width << ", " << "height: " << frame.height << std::endl;

  std::cout << "Circle moved on:" << "("<< 0 << "," << -15 << ")" << std::endl;
  circleTest.move(0,-15);
  circleTest.coutInfo();

  std::cout << "Circle moved to:" << "("<< movePoint.x << "," << movePoint.y << ")" << std::endl;
  circleTest.move(movePoint);
  circleTest.coutInfo();

  std::cout << "--------------------------------------------------" << std::endl;

  return 0;
}
