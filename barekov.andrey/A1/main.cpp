#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rect1 {point_t{1, 2.3}, 4.56, 7};
  Rectangle rect2 {8, -9.1, 0.11, 12};
  Circle circ1 {point_t{13, -1.4}, 1.51};
  Circle circ2 {6.17, 18, 1.9};

  Shape* figures[4] = {&rect1, &rect2, &circ1, &circ2};

  for (int i = 0; i < 4; i++)
  {
    std::cout << "\nArea of figure No. " << i+1 << " is "
        << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of figure No. " << i << " is ("
        << figures[i]->getFrameRect().pos.x << "; "
        << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Frame Rectangle size of figure No. " << i << " is "
        << figures[i]->getFrameRect().width << "x"
        << figures[i]->getFrameRect().height << "\n";
  }

  std::cout << "\nThe position of the first rectangle is ("
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")\n";
  std::cout << "\nMoving first rectangle to a point of (3; 4)";
  figures[0]->move({3, 4});
  std::cout << "\nNow the position of the first rectangle is ("
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")\n";

  std::cout << "\nThe position of the first circle is ("
      << figures[2]->getPos().x << "; "
      << figures[2]->getPos().y << ")\n";
  std::cout << "\nMoving first circle -8 along x and +5.67 along y";
  figures[2]->move(-8, 5.67);
  std::cout << "\nNow the position of the first circle is ("
      << figures[2]->getPos().x << "; "
      << figures[2]->getPos().y << ")\n";

  return 0;
}
