#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameRect(const besedin::Shape &shape)
{
  besedin::rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Width: " << frameRect.width << "  ";
  std::cout << "Height: " << frameRect.height << "  ";
  std::cout << "Center: ( " << frameRect.pos.x << " , " << frameRect.pos.y << " )" << std::endl;
}

void printArea(const besedin::Shape &shape)
{
  std::cout << "Area: " << shape.getArea() << std::endl;
}

void printCenter(const besedin::Shape &shape)
{
  std::cout << "Center: ( " << shape.getFrameRect().pos.x << " , " << shape.getFrameRect().pos.y << " )";
}

int main()
{
  besedin::point_t pointCenter = {5.0, 5.0};
  besedin::Rectangle rectangle(3.0, 3.0, pointCenter);
  besedin::Circle circle(7.0, pointCenter);
  besedin::point_t pointNewCenter = {15.0, 15.0};
  const double scale = 2.0;

  std::cout << "Rectangle" << std::endl;
  printFrameRect(rectangle);
  printArea(rectangle);
  rectangle.scale(scale);
  printArea(rectangle);
  rectangle.move(3.0, 3.0);
  printCenter(rectangle);
  std::cout << std::endl << std::endl;

  std::cout << "Circle" << std::endl;
  printFrameRect(circle);
  printArea(circle);
  circle.scale(scale);
  printArea(circle);
  circle.move(pointNewCenter);
  printCenter(circle);
  std::cout << std::endl;

  return 0;
}
