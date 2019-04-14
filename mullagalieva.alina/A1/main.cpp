#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Circle circle1{point_t{4.12, 6.7}, 3.5};
  Circle circle2{1.23, 5.67, 134.3};
  Rectangle rectangle1{point_t{5.86, 9.06}, 4.5, 3.21};
  Rectangle rectangle2{7.65, 3.65, 8.91, 13.01};
  Triangle triangle1{point_t{3.17, 8.1}, 3, 4, 5};
  Triangle triangle2{6.89, 9.123, 5, 11.5, 7.87};

  Shape* figures[] = {&circle1, &circle2, &rectangle1, &rectangle2, &triangle1, &triangle2};
  int size = sizeof(figures) / sizeof(Shape);
  for (int i = 0; i < size; i++)
  {
    std::cout << "Figure num:" << i << "\n";
    std::cout << "Area: " << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle centre: ("
        << figures[i]->getFrameRect().pos.x << "; "
        << figures[i]->getFrameRect().pos.y << ")" << "\n";
    std::cout << "Frame Rectangle width: "
        << figures[i]->getFrameRect().width << "\n";
    std::cout << "Frame Rectangle height: "
        << figures[i]->getFrameRect().height << "\n";
  }

  std::cout << "Position of the first figure: (" // moving rectangle
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")" << "\n";
  std::cout << "Moving to the point (1; 2.9)" << "\n";
  figures[0]->move({1, 2.9});
  std::cout << "New position of the first figure: ("
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")" << "\n";

  std::cout << "Position of the third figure: (" // moving circle
      << figures[3]->getPos().x << "; "
      << figures[3]->getPos().y << ")" << "\n";
  std::cout << "Moving dx = 6.1, dy = 5" << "\n";
  figures[3]->move(6.1, 5);
  std::cout << "New position of the third figure: ("
      << figures[3]->getPos().x << "; "
      << figures[3]->getPos().y << ")" << "\n";

  std::cout << "Position of the fifth figure: (" // moving triangle
      << figures[5]->getPos().x << "; "
      << figures[5]->getPos().y << ") " << "\n";
  std::cout << "Moving to the point (2.9; 4.1)" << "\n";
  figures[5]->move({2.9, 4.1});
  std::cout << "New position of the fifth figure: ("
      << figures[5]->getPos().x << "; "
      << figures[5]->getPos().y << ")";
    
  return 0;
}
