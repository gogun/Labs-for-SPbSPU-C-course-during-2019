#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"

void printShapeInfo(const kozhin::Shape *shape)
{
  // Check for null pointer
  assert(shape != nullptr);
  // Print info about shape
  double shapeArea = shape->getArea();
  kozhin::rectangle_t shapeFrameRect = shape->getFrameRect();
  std::cout << "Shape area is " << shapeArea << '\n';
  std::cout << "Shape frame rect params are: \n";
  std::cout << "\tWidth: " << shapeFrameRect.width << '\n';
  std::cout << "\tHeight: " << shapeFrameRect.height << '\n';
  std::cout << "\tCenter: x: " << shapeFrameRect.pos.x << ", y: " << shapeFrameRect.pos.y << "\n\n";
}

int main()
{
  // Initializing test circle and rectangle
  kozhin::Circle testCircle({10.0, -5.5}, 5.0);

  // Printing initial circle info
  std::cout << "Initial test circle params: \n";
  printShapeInfo(&testCircle);

  // Moving circle relatively and printing new info
  testCircle.move({-5.2, 6.8});
  std::cout << "Moved circle to point -5.2 6.8: \n";
  printShapeInfo(&testCircle);

  // Scaling Circle
  testCircle.scale(5.2);
  std::cout << "Scaled circle in 5.2 times: \n";
  printShapeInfo(&testCircle);

  // Initializing test rectangle
  kozhin::Rectangle testRect({10.5, -1.5}, 15, 6);

  // Priniting initial rectangle info
  std::cout << "Initial test rectangle params: \n";
  printShapeInfo(&testRect);

  // Moving rectangle absolutely and print new info
  testRect.move(3.1, -5.6);
  std::cout << "Changed rectangle postion by 3.1 -5.6: \n";
  printShapeInfo(&testRect);

  // Scale Rectangle
  testRect.scale(2.3);
  std::cout << "Scaled rectangle in 2.3 times: \n";
  printShapeInfo(&testRect);
  return 0;
}
