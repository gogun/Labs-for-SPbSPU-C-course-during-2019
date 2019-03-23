#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle testCircle({10.0, -5.5}, 5.0);
  double testCircleArea = testCircle.getArea();
  rectangle_t testCircleFrame = testCircle.getFrameRect();

  std::cout << "Test circle area is " << testCircleArea << std::endl;
  std::cout << "Test circle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testCircleFrame.width << std::endl;
  std::cout << "\tHeight: " << testCircleFrame.height << std::endl;
  std::cout << "\tCenter: " << testCircleFrame.pos.x << ' ' << testCircleFrame.pos.y << std::endl;
  std::cout << std::endl;

  testCircle.move({-5.2, 6.8});
  std::cout << "Moved circle to point -5.2 6.8" << std::endl;

  testCircleArea = testCircle.getArea();
  testCircleFrame = testCircle.getFrameRect();

  std::cout << "Test circle area is " << testCircleArea << std::endl;
  std::cout << "Test circle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testCircleFrame.width << std::endl;
  std::cout << "\tHeight: " << testCircleFrame.height << std::endl;
  std::cout << "\tCenter: " << testCircleFrame.pos.x << ' ' << testCircleFrame.pos.y << std::endl;
  std::cout << std::endl;

  Rectangle testRect({10.5, -1.5}, 15, 6);
  double testRectArea = testRect.getArea();
  rectangle_t testRectFrame = testRect.getFrameRect();

  std::cout << "Test reactangle area is " << testRectArea << std::endl;
  std::cout << "Test reactangle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRectFrame.width << std::endl;
  std::cout << "\tHeight: " << testRectFrame.height << std::endl;
  std::cout << "\tCenter: " << testRectFrame.pos.x << ' ' << testRectFrame.pos.y << std::endl;
  std::cout << std::endl;

  testRect.move(3.1, -5.6);
  std::cout << "Changed rectangle postion by 3.1 -5.6" << std::endl;

  testRectArea = testRect.getArea();
  testRectFrame = testRect.getFrameRect();

  std::cout << "Test reactangle area is " << testRectArea << std::endl;
  std::cout << "Test reactangle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRectFrame.width << std::endl;
  std::cout << "\tHeight: " << testRectFrame.height << std::endl;
  std::cout << "\tCenter: " << testRectFrame.pos.x << ' ' << testRectFrame.pos.y << std::endl;
  return 0;
}
