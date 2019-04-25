#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void printInfo(const Shape * pointer)
{
  assert(pointer);
  std::cout << "Shape's area: " << pointer->getArea() << "\n";
  std::cout << "Frame rectangle's centre: " << "(" << pointer->getFrameRect().pos.x << ", " << pointer->getFrameRect().pos.y << ")\n";
  std::cout << "Frame rectangle's width - " << pointer->getFrameRect().width << " & height - " << pointer->getFrameRect().height << "\n";
}

void printShapeInfo(Shape * pointer)
{
  assert(pointer);
  printInfo(pointer);
  std::cout << "--Move shape to a point (1, 2)--\n";
  pointer->move({1, 2});
  printInfo(pointer);
  std::cout << "--Shift shape's x by 3 & y by 4--\n";
  pointer->move(3, 4);
  printInfo(pointer);
  std::cout << "\n\n";
}

int main()
{
  Circle circleSample(12.34, {5, 6});
  Shape * shapePointer = &circleSample;
  std::cout << "--Circle:--\n";
  printShapeInfo(shapePointer);

  Rectangle rectangleSample(7, 8, {9, 10});
  shapePointer = &rectangleSample;
  std::cout << "--Rectangle:--\n";
  printShapeInfo(shapePointer);

  Triangle triangleSample({5, 5}, {16, 8}, {19, 15});
  shapePointer = &triangleSample;
  std::cout << "--Triangle:--\n";
  printShapeInfo(shapePointer);

  return 0;
}
