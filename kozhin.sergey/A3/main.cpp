#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

void printShapeInfo(const kozhin::Shape& shape)
{
  double shapeArea = shape.getArea();
  kozhin::rectangle_t shapeFrameRect = shape.getFrameRect();
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
  printShapeInfo(testCircle);

  // Moving circle relatively and printing new info
  testCircle.move({-5.2, 6.8});
  std::cout << "Moved circle to point -5.2 6.8: \n";
  printShapeInfo(testCircle);

  // Scaling Circle
  testCircle.scale(2);
  std::cout << "Scaled circle in 2 times: \n";
  printShapeInfo(testCircle);

  // Initializing test rectangle
  kozhin::Rectangle testRect({10.5, -1.5}, 15, 6);

  // Priniting initial rectangle info
  std::cout << "Initial test rectangle params: \n";
  printShapeInfo(testRect);

  // Moving rectangle absolutely and print new info
  testRect.move(-19.5, -28.4);
  std::cout << "Changed rectangle postion by 3.1 -5.6: \n";
  printShapeInfo(testRect);

  // Scale Rectangle
  testRect.scale(2.3);
  std::cout << "Scaled rectangle in 2.3 times: \n";
  printShapeInfo(testRect);

  // Creating composite shape based on previously used shapes
  kozhin::CompositeShape testComposite(testCircle);
  testComposite.add(testRect);

  std::cout << "Initial composite shape params: \n";
  printShapeInfo(testComposite);

  // Moving relatively
  testComposite.move(2.5, -3);
  std::cout << "Composite shape after moving relatively by 2.5 -3: \n";
  printShapeInfo(testComposite);

  // Scaling
  testComposite.scale(2.5);
  std::cout << "Composite shape after scaling by 2.5: \n";
  printShapeInfo(testComposite);

  // Accesing member shape
  std::cout << "Circle accesed through composite shape: \n";
  printShapeInfo(testComposite[0]);

  // Deleting memeber shape
  testComposite.remove(0);
  std::cout << "Composite after deleting circle: \n";
  printShapeInfo(testComposite);
  return 0;
}
