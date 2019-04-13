#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printArea(const Shape& sh)
{
  std::cout << "Area - " << sh.getArea() << '\n';
}

void printFrameRect(const Shape& sh)
{
  std::cout << "Frame rectangle width - " << sh.getFrameRect().width << '\n';
  std::cout << "Frame rectangle height - " << sh.getFrameRect().height << '\n';
}

void printPosition(const Shape& sh)
{
  std::cout << "Position - " << sh.getFrameRect().pos.x << ',' << sh.getFrameRect().pos.y << '\n';
}

int main()
{
  point_t centerPoint{0, 0};
  Rectangle rect(centerPoint, 2, 2);
  Circle cir(centerPoint, 2);
  Triangle tri(centerPoint, 1, 1);

  std::cout << "RECTANGLE:\n";
  printArea(rect);
  printFrameRect(rect);
  printPosition(rect);
  std::cout << '\n';

  centerPoint = {1, 1};
  rect.move(centerPoint);
  std::cout << "Moved rectangle to (1, 1)\n";
  printPosition(rect);

  rect.move(1, 0);
  std::cout << "Moved rectangle by (1, 0)\n";
  printPosition(rect);
  std::cout << '\n';

  std::cout << "CIRCLE:\n";
  printArea(cir);
  printFrameRect(cir);
  printPosition(cir);
  std::cout << '\n';

  centerPoint = {2, 2};
  cir.move(centerPoint);
  std::cout << "Moved circle to (2, 2)\n";
  printPosition(cir);

  cir.move(0, 2);
  std::cout << "Moved circle by (0, 2)\n";
  printPosition(cir);
  std::cout << '\n';

  std::cout << "TRIANGLE:\n";
  printArea(tri);
  printFrameRect(tri);
  printPosition(tri);
  std::cout << '\n';

  centerPoint = {1, -1};
  tri.move(centerPoint);
  std::cout << "Moved triangle to (1, -1)\n";
  printPosition(tri);

  tri.move(-1, 1);
  std::cout << "Moved triangle by (-1, 1)\n";
  printPosition(tri);
  std::cout << '\n';
}
