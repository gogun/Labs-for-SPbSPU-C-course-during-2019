#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "shape.hpp"

void printFigureInfo(const Shape *figure)
{
  rectangle_t frameRect = figure->getFrameRect();
  std::cout << "Center of figure: (" << frameRect.pos.x << ", " << frameRect.pos.y << ")\n";
  std::cout << "Figure width: " << frameRect.width << "\n";
  std::cout << "Figure height: " << frameRect.height << "\n";
  std::cout << "Figure area: " << figure->getArea() << "\n";
}

int main()
{
  //Working with rectangle
  Rectangle rectangle({6, 8}, 5, 2);
  Shape *figure = &rectangle;
  std::cout << "Rectangle information after initialization:" << "\n";
  printFigureInfo(figure);
  rectangle.move({1, 2});
  rectangle.move(3, 9);
  std::cout << "Rectangle information after moving:" << "\n";
  printFigureInfo(figure);

  //Working with circle
  Circle circle({7, 5}, 3);
  figure = &circle;
  std::cout << "Circle information after initialization:" << "\n";
  printFigureInfo(figure);
  circle.move({5, 5});
  circle.move(4, 4);
  std::cout << "Circle information after moving:" << "\n";
  printFigureInfo(figure);
  return 0;
}