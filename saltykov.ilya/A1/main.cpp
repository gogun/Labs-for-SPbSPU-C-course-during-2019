#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle1{point_t{3.15, 3.45}, 5};
  Circle circle2{-3.15, -3.45, 5};
  Rectangle rectangle1{point_t{5, 4.15}, 4, 2};
  Rectangle rectangle2{-5, -4.15, 4, 2};

  Shape* figures[] = {&circle1, &circle2, &rectangle1, &rectangle2};
  const int Size = sizeof(figures) / sizeof(Shape);

  for (int i = 0; i < Size; i++)
  {
    std::cout << "\nArea of figure No. " << i << " is "
        << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of figure No. " << i << " is ("
        << figures[i]->getFrameRect().pos.x << "; "
        << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Frame Rectangle width of figure No. " << i << " is "
        << figures[i]->getFrameRect().width << "\n";
    std::cout << "Frame Rectangle height of figure No. " << i << " is "
        << figures[i]->getFrameRect().height << "\n";
  }

  std::cout << "\nThe position of the first circle is ("
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")\n";
  std::cout << "\nMoving first circle to a point of (1.47; 4.54)";
  figures[0]->move({ 1.47, 4.54 });
  std::cout << "\nThe position of the first circle is ("
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")\n";

  std::cout << "\nThe position of the second rectangle is ("
      << figures[3]->getPos().x << "; "
      << figures[3]->getPos().y << ")\n";
  std::cout << "\nMoving second rectangle, dx = -1.234, dy = 5.67";
  figures[3]->move(-1.234, 5.67);
  std::cout << "\nThe position of the second rectangle is ("
      << figures[3]->getPos().x << "; "
      << figures[3]->getPos().y << ")\n";

  return 0;
}
