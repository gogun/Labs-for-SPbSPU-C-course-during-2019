#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void printRect(const Shape & shape)
{
  std::cout << "Frame rectangle: x = " << shape.getFrameRect().pos.x;
  std::cout << " y = " << shape.getFrameRect().pos.y;
  std::cout << " width = " << shape.getFrameRect().width;
  std::cout << " height = " << shape.getFrameRect().height << '\n';
}

void showProgramWork(Shape & shape)
{
  std::cout << "Area = " << shape.getArea() << '\n';
  printRect(shape);
  double x = 2;
  double y = 2;
  shape.move({x, y});
  std::cout << "Move to: x = " << x << " y = " << y << '\n';
  printRect(shape);
  double dx = 5;
  double dy = 10;
  shape.move(dx, dy);
  std::cout << "Move by: dx = " << dx << " dy = " << dy << '\n';
  printRect(shape);
}

int main()
{
  std::cout << "The first object is Circle:" << '\n';
  Circle circle(6.6, {3, 7});
  showProgramWork(circle);
  std::cout << "The second object is Rectangle:" << '\n';
  Rectangle rectangle(5, 6, {2, 4});
  showProgramWork(rectangle);
  std::cout << "The third object is Triangle:" << '\n';
  Triangle triangle({3, 7}, {5, 2}, {7, 4});
  triangle.printCenter();
  showProgramWork(triangle);
  triangle.showCoord();
  return 0;
}
