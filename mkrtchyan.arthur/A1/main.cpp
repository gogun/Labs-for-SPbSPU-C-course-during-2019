#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printShapeInfo(const Shape * pointer)
{
  assert(pointer);
  std::cout << "Shape's area: " << pointer->getArea() << "\n";
  std::cout << "Frame rectangle's centre: " << "( " << pointer->getFrameRect().pos.x << "," << pointer->getFrameRect().pos.y << " )\n";
  std::cout << "Frame rectangle's width - " << pointer->getFrameRect().width << " & height - " << pointer->getFrameRect().height << "\n";
}

int main()
{
  Circle circleSample(12.34, {5, 6});
  Shape * shapePointer = &circleSample;
  std::cout << "--Circle:--\n";
  printShapeInfo(shapePointer);
  std::cout << "--Move shape to a point (1, 2)--\n";
  shapePointer->move({1, 2});
  printShapeInfo(shapePointer);
  std::cout << "--Shift shape's x by 3 & y by 4--\n";
  shapePointer->move(3, 4);
  printShapeInfo(shapePointer);

  std::cout << "\n\n";

  Rectangle rectangleSample(7, 8, {9, 10});
  shapePointer = &rectangleSample;
  std::cout << "--Rectangle:--\n";
  printShapeInfo(shapePointer);
  std::cout << "--Move shape to a point (5, 6)--\n";
  shapePointer->move({5, 6});
  printShapeInfo(shapePointer);
  std::cout << "--Shift shape's x by 7 & y by 8--\n";
  shapePointer->move(7, 8);
  printShapeInfo(shapePointer);

  std::cout << "\n\n";

  Triangle triangleSample ({5, 5}, {16, 8}, {19, 15});
  shapePointer = &triangleSample;
  std::cout << "--Triangle:--\n";
  printShapeInfo(shapePointer);
  std::cout << "--Move shape to a point (9, 10)--\n";
  shapePointer->move({9, 10});
  printShapeInfo(shapePointer);
  std::cout << "--Shift shape's x by 11 & y by 12--\n";
  shapePointer->move(11, 12);
  printShapeInfo(shapePointer);

  return 0;
}
