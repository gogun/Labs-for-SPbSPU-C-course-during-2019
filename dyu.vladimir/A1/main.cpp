#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"


void writeInfo(rectangle_t rect)
{
  std::cout << "x:" << rect.pos.x << std::endl;
  std::cout << "y:" << rect.pos.y << std::endl;
  std::cout << "Frame Rect:" << std::endl;
  std::cout << "Width:" << rect.width << std::endl;
  std::cout << "Height:" << rect.height << std::endl;
}

void showresult(const Shape &shape)
{
  std::cout << "Area:" << shape.getArea() << std::endl;
  std::cout << "position after moving: ";
  std::cout << "Center:(" << shape.getFrameRect().pos.x << "," << shape.getFrameRect().pos.y << ")";
  std::cout << std::endl;
  writeInfo(shape.getFrameRect());
}

void showpos(const Shape &shape)
{
  std::cout << "start position: ";
  std::cout << "Center:(" << shape.getFrameRect().pos.x << "," << shape.getFrameRect().pos.y << ")";
  std::cout << std::endl;
}

int main()
{
  Rectangle rect(3.0, 6.0, {10.0, 10.0});
  std::cout << "Rectangle" << std::endl;
  showpos(rect);
  rect.move({0, 0});
  rect.move(2,2);
  showresult(rect);
  std::cout << std::endl;
  std::cout << std::endl;

  Circle circle(3.0, {2.0, 3.0});
  std::cout << "Circle" << std::endl;
  showpos(circle);
  circle.move({0, 0});
  circle.move(3,5);
  showresult(circle);
  std::cout << std::endl;

  return 0;
}
