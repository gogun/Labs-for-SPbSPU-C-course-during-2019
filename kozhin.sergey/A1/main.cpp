#include "circle.hpp"
#include "rectangle.hpp"
#include <iostream>

int main()
{
  Circle fCircle({10.0, -5.5}, 5.0);
  double testArea = fCircle.getArea();
  rectangle_t testRect = fCircle.getFrameRect();

  std::cout << "Test circle area is " << testArea << std::endl;
  std::cout << "Test circle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRect.width << std::endl;
  std::cout << "\tHeight: " << testRect.height << std::endl;
  std::cout << "\tCenter: " << testRect.pos.x << ' ' << testRect.pos.y << std::endl;
  std::cout << std::endl;

  fCircle.move(1.5, 6.3);
  testRect = fCircle.getFrameRect();

  std::cout << "New test circle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRect.width << std::endl;
  std::cout << "\tHeight: " << testRect.height << std::endl;
  std::cout << "\tCenter: " << testRect.pos.x << ' ' << testRect.pos.y << std::endl;
  std::cout << std::endl;


  Rectangle fRect({10.5, -1.5}, 15, 6);
  double testAreaR = fRect.getArea();
  rectangle_t testRectR = fRect.getFrameRect();

  std::cout << "Test reactangle area is " << testAreaR << std::endl;
  std::cout << "Test reactangle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRectR.width << std::endl;
  std::cout << "\tHeight: " << testRectR.height << std::endl;
  std::cout << "\tCenter: " << testRectR.pos.x << ' ' << testRectR.pos.y << std::endl;

  fRect.moveTo(5.8, 9.15);
  testRectR = fRect.getFrameRect();

  std::cout << " New test reactangle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRectR.width << std::endl;
  std::cout << "\tHeight: " << testRectR.height << std::endl;
  std::cout << "\tCenter: " << testRectR.pos.x << ' ' << testRectR.pos.y << std::endl;

  return 0;
}
