#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  konev::Rectangle r1({1.0, 1.0}, 3.0, 3.0);
  std::cout << r1.getArea() << std::endl;
  r1.scale(2.0);
  std::cout << r1.getArea() << std::endl;

  konev::Rectangle r2({2.0, 2.0}, 1.0, 4.0);
  r2.move(1.0, 2.0);

  konev::Circle c1({3.0, 1.0}, 3.0);
  std::cout << c1.getArea() << std::endl;
  c1.scale(2.0);
  std::cout << c1.getArea() << std::endl;

  konev::Circle c2({1.0, 2.0}, 4.0);
  c2.move({3.0, 5.0});

  konev::Shape *circP = &c2;
  konev::rectangle_t tempRect = circP->getFrameRect();
  std::cout << tempRect.pos.x << " " << tempRect.pos.y << " " << tempRect.width << " " << tempRect.height << std::endl;

  konev::Shape *rectP = &r2;
  tempRect = rectP->getFrameRect();
  std::cout << tempRect.pos.x << " " << tempRect.pos.y << " " << tempRect.width << " " << tempRect.height << std::endl;

  return 0;
}
