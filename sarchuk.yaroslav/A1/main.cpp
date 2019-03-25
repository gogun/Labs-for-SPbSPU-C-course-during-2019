#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void moveAndWrite(Shape *shape, const point_t &pos)
{
  std::cout << "Move to point" << pos.x << "," << pos.y << "\n";
  shape->move(pos);
  shape->writeInfo();
}

void moveAndWrite(Shape *shape, double dx, double dy)
{
  std::cout << "Add to X " << dx << ", Add to Y " << dy << "\n";
  shape->move(dx, dy);
  shape->writeInfo();
}

int main()
{
  Circle circle({1, 0}, 2);
  std::cout << "New circle:\n";
  circle.writeInfo();
  Rectangle rect(circle.getFrameRect());
  std::cout << "Rectangle around circle\n";
  rect.writeInfo();
  moveAndWrite(&circle, {8, 8});
  moveAndWrite(&circle, 2, 2);

  Rectangle rectangle({2, 5}, 4, 4);
  std::cout << "New Rectangle\n";
  rectangle.writeInfo();
  moveAndWrite(&rectangle, {8, 8});
  moveAndWrite(&rectangle, 2, 2);

  return 0;
}
