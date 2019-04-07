#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printShapeInfo(const Shape * pointer) {
  std::cout<< "Area: " << pointer->getArea() << "\n";
  std::cout<< "Centre: " << "( " << pointer->getFrameRect().pos.x << "," << pointer->getFrameRect().pos.y << " )\n";
  std::cout<< "Frame rectangle's width - " << pointer->getFrameRect().width << " & height - " << pointer->getFrameRect().height << "\n";
}

int main() {
  Circle circleSample(12.34,{5,6});
  Shape * shapePointer = &circleSample;
  std::cout << "--Circle:--\n";
  printShapeInfo(shapePointer);
  std::cout<< "--Move to a point (1,2)--\n";
  shapePointer->move({1,2});
  printShapeInfo(shapePointer);
  std::cout<< "--Shift x by 3 & y by 4--\n";
  shapePointer->move(3,4);
  printShapeInfo(shapePointer);

  std::cout<< "\n\n";

  Rectangle rectangleSample(7,8,{9,10});
  shapePointer = &rectangleSample;
  std::cout << "--Rectangle:--\n";
  printShapeInfo(shapePointer);
  std::cout<< "--Move to a point (5,6)--\n";
  shapePointer->move({5,6});
  printShapeInfo(shapePointer);
  std::cout<< "--Shift x by 7 & y by 8--\n";
  shapePointer->move(7,8);
  printShapeInfo(shapePointer);

  return 0;
}
