#include "circle.hpp"
#include "reactangle.hpp"
#include <iostream>

int main()
{
  Circle fCircle({10.0, -5.5}, 5.0);
  float testArea = fCircle.getArea();
  reactangle_t testRect = fCircle.getFrameRect();

  std::cout << "Test circle area is " << testArea << std::endl;
  std::cout << "Test circle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRect.width << std::endl;
  std::cout << "\tHeight: " << testRect.heigth << std::endl;
  std::cout << "\tCenter: " << testRect.pos.x << ' ' << testRect.pos.y << std::endl;
  std::cout << std::endl;

  Reactangle fRect({10.5, -1.5}, 15, 6);
  float testAreaR = fRect.getArea();
  reactangle_t testRectR = fRect.getFrameRect();

  std::cout << "Test reactangle area is " << testAreaR << std::endl;
  std::cout << "Test reactangle frame rect params are: " << std::endl;
  std::cout << "\tWidth: " << testRectR.width << std::endl;
  std::cout << "\tHeight: " << testRectR.heigth << std::endl;
  std::cout << "\tCenter: " << testRectR.pos.x << ' ' << testRectR.pos.y << std::endl;
  return 0;
}
