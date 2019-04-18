#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"


void showRectangle_t(ryabikin::rectangle_t data)
{
  std::cout << "Width = " << data.width << "\n";
  std::cout << "Height = " << data.height << "\n";
  std::cout << "(X = " << data.pos.x << ";";
  std::cout << "Y = " << data.pos.y << ")" << "\n";
}

void showAll(const ryabikin::Shape * shape)
{
  assert(shape != nullptr);
  std::cout << "Area = " << shape->getArea() << "\n";
  showRectangle_t(shape->getFrameRect());
}

int main()
{
  ryabikin::Rectangle rectnagle(3.00, 4.00, { 5.00, 4.00 });
  std::cout << "Rectangle = " << "\n";
	showAll(&rectnagle);
  rectnagle.scale(3.0);
  std::cout << "After scale - " << "\n";
  showAll(&rectnagle);
  rectnagle.move({ .x = 7.00, .y = 8.00 });
  std::cout << "After move - " << "\n";
  showAll(&rectnagle);
  ryabikin::Circle circle(3.00, { 1.00, 3.00 });
  std::cout << "Circle = " << "\n";
  showAll(&circle);
  circle.scale(4.00);
  std::cout << "After scale - " << "\n";
  showAll(&circle);
  circle.move(3.00, -1.5);
  std::cout << "After move - " << "\n";
  showAll(&circle);
  return 0;
}
