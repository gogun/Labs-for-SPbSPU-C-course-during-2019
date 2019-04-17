#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void writeArea(const pavlova::Shape &shape)
{
  std::cout << "Area = " << shape.getArea() << "\n";
}

void writeCenter(const pavlova::Shape &shape)
{
  std::cout << "Center (" << shape.getFrameRect().pos.x
            << ", " << shape.getFrameRect().pos.y << ")" << "\n";
}

void writeFrameRect(const pavlova::Shape &shape)
{
  pavlova::rectangle_t frameR = shape.getFrameRect();
  std::cout << "Frame: " << frameR.height
            << "(height), " << frameR.width
            << "(width), (" << frameR.pos.x
            << ", " << frameR.pos.y
            << ")" << "\n";
}

int main()
{
  pavlova::Circle circle(3.5, {6.1, 6.1});
  std::cout << "Circle:" << "\n";
  writeFrameRect(circle);
  writeCenter(circle);
  writeArea(circle);

  std::cout << "Scaling" << "\n";
  circle.scale(2);
  std::cout << "New area: " << circle.getArea() << "\n";
  std::cout << "\n";

  pavlova::Rectangle rectangle(4.15, 4.15, {5, 5});
  std::cout << "Rectangle:" << "\n";
  writeFrameRect(rectangle);
  writeCenter(rectangle);
  writeArea(rectangle);

  std::cout << "Scaling" << "\n";
  rectangle.scale(2);
  std::cout << "New area: " << rectangle.getArea() << "\n";

  return 0;
}
