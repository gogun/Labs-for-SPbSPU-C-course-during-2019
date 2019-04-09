#include <iostream>
#include <cassert>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

void moveAndWrite(sarchuk::Shape *shape, const sarchuk::point_t &pos)
{
  if(shape == nullptr)
  {
    throw std::invalid_argument("Pointer does not indicate anything");
  }
  std::cout << "Move to point " << pos.x << ", " << pos.y << "\n";
  shape->move(pos);
  shape->writeInfo();
}

void moveAndWrite(sarchuk::Shape *shape, double dx, double dy)
{
  if(shape == nullptr)
  {
    throw std::invalid_argument("Pointer does not indicate anything");
  }
  std::cout << "Add to X " << dx << ", Add to Y " << dy << "\n";
  shape->move(dx, dy);
  shape->writeInfo();
}

void scaleAndWrite(sarchuk::Shape *shape, double mult)
{
  if(shape == nullptr)
  {
    throw std::invalid_argument("Pointer does not indicate anything");
  }
  std::cout << "Scaling shape with multiplier of " << mult << "\n";
  shape->scale(mult);
  shape->writeInfo();
}

int main()
{
  sarchuk::Circle circle({1, 0}, 2);
  std::cout << "New circle:\n";
  circle.writeInfo();
  sarchuk::Rectangle rect(circle.getFrameRect());
  std::cout << "Rectangle around circle\n";
  rect.writeInfo();
  moveAndWrite(&circle, {8, 8});
  moveAndWrite(&circle, 2, 2);
  scaleAndWrite(&circle, 3);

  sarchuk::Rectangle rectangle({2, 5}, 4, 4);
  std::cout << "New Rectangle\n";
  rectangle.writeInfo();
  moveAndWrite(&rectangle, {8, 8});
  moveAndWrite(&rectangle, 2, 2);
  scaleAndWrite(&rectangle, 2);

  return 0;
}
