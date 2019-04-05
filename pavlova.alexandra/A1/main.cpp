#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void writeArea(const Shape & shape)
{
  std::cout << "Area = " << shape.getArea() << "\n";
}

void writeCenter(const Shape & shape)
{
  std::cout << "Center (" << shape.getFrameRect().pos.x << ", " << shape.getFrameRect().pos.y << ")" << "\n";
}

void writeFrameRect(const Shape & shape)
{
  rectangle_t frameR = shape.getFrameRect();
  std::cout << "Frame: " << frameR.height << "(height), " << frameR.width
    << "(width), (" << frameR.pos.x << ", " << frameR.pos.y << ")" << "\n";
}

int main()
{
  Circle circle(3, {6, 6});
  std::cout << "Circle:" << "\n";
  writeArea(circle);
  writeFrameRect(circle);
  writeCenter(circle);

  point_t pointNewCircle = {10, 10};
  circle.move(pointNewCircle);
  writeCenter(circle);

  Rectangle rectangle(4, 4, {5, 5});
  std::cout << "Rectangle:" << "\n";
  writeFrameRect(rectangle);
  writeArea(rectangle);

  rectangle.move(8, 8);
  writeCenter(rectangle);

  return 0;
}
