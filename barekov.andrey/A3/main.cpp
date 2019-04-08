#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

int main()
{
  barekov::Rectangle rect1 {barekov::point_t{1, 2.3}, 4.56, 7};
  barekov::Rectangle rect2 {8, -9.1, 0.11, 12};
  barekov::Circle circ1 {barekov::point_t{13, -1.4}, 1.51};
  barekov::Circle circ2 {6.17, 18, 1.9};

  barekov::Shape* figures[] = {&rect1, &rect2, &circ1, &circ2};
  const int Size = sizeof(figures) / sizeof(barekov::Shape);

  for (int i = 0; i < Size; i++)
  {
    std::cout << "\nArea of figure No. " << i << " is "
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

  figures[0]->showScalableParameters();
  std::cout << "Scaling first rectangle by a factor of 1.3";
  figures[0]->scale(1.3);
  figures[0]->showScalableParameters();

  figures[2]->showScalableParameters();
  std::cout << "Scaling first circle by a factor of 2.4";
  figures[2]->scale(2.4);
  figures[2]->showScalableParameters();

  barekov::Rectangle partOfComposite1 {3, 11, 6, 6};
  barekov::Rectangle partOfComposite2 {11, 3, 6, 6};
  barekov::Circle partOfComposite3 {9, 13, 3};

  barekov::CompositeShape composite(&partOfComposite1);
  composite.addShape(&partOfComposite2);
  composite.addShape(&partOfComposite3);

  std::cout << "\nArea of the composite shape is " << composite.getArea() << "\n";
  std::cout << "Frame Rectangle position of the composite shape is ("
      << composite.getFrameRect().pos.x << "; "
      << composite.getFrameRect().pos.y << ")\n";
  composite.showScalableParameters();
  std::cout << "Scaling the composite shape by a factor of 0.5";
  composite.scale(0.5);
  composite.showScalableParameters();

  std::cout << "\nThe position of the composite shape is ("
      << composite.getPos().x << "; "
      << composite.getPos().y << ")\n";
  std::cout << "\nMoving the composite shape to a point of (3; 4)";
  composite.move({3, 4});
  std::cout << "\nNow the position of the composite shape is ("
      << composite.getPos().x << "; "
      << composite.getPos().y << ")\n";
  std::cout << "\nMoving the composite shape -8 along x and +5.67 along y";
  composite.move(-8, 5.67);
  std::cout << "\nNow the position of the composite shape is ("
      << composite.getPos().x << "; "
      << composite.getPos().y << ")\n";

  return 0;
}
