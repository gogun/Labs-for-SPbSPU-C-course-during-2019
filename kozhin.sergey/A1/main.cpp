#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void printShapeInfo(const Shape *shape)
{
  double shapeArea = shape->getArea();
  rectangle_t shapeFrameRect = shape->getFrameRect();
  std::cout << "Shape area is " << shapeArea << '\n';
  std::cout << "Shape frame rect params are: \n";
  std::cout << "\tWidth: " << shapeFrameRect.width << '\n';
  std::cout << "\tHeight: " << shapeFrameRect.height << '\n';
  std::cout << "\tCenter: x: " << shapeFrameRect.pos.x << ", y: " << shapeFrameRect.pos.y << "\n\n";
}

int main()
{
  // Initializing test circle and rectangle
  Circle testCircle({10.0, -5.5}, 5.0);
  Rectangle testRect({10.5, -1.5}, 15, 6);

  // Using testShape to work with circle
  Shape *testShape = &testCircle;

  // Printing initial circle info
  std::cout << "Initial test circle params: \n";
  printShapeInfo(testShape);

  // Moving circle relatively and printing new info
  testCircle.move({-5.2, 6.8});
  std::cout << "Moved circle to point -5.2 6.8: \n";
  printShapeInfo(testShape);

  // Now using testShape to work with rectangle
  testShape = &testRect;

  // Priniting initial rectangle info
  std::cout << "Initial test rectangle params: \n";
  printShapeInfo(testShape);

  // Moving rectangle absolutely and print new info
  testRect.move(3.1, -5.6);
  std::cout << "Changed rectangle postion by 3.1 -5.6: \n";
  printShapeInfo(testShape);

  return 0;
}
