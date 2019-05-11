#include <iostream>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  //create some shapes
  zybkin::Circle circle1({1.2, 1.2}, 3.0);
  zybkin::Circle circle2({-0.2, 5.3}, 2.0);
  zybkin::Rectangle rect1({1.6, 1.6}, 5.0, 3.0);
  zybkin::Rectangle rect2({-7.3, 2.6}, 8.2, 5.3);

  std::cout << "Create composite shape:\n";
  zybkin::CompositeShape compositeShape(&circle1);

  compositeShape.printInfo();

  std::cout << "Add other shapes in composite:\n";
  compositeShape.add(&rect1);
  compositeShape.add(&rect2);
  compositeShape.add(&circle2);
  compositeShape.printInfo();

  std::cout << "Shift at (3,3)\n";
  compositeShape.move(3, 3);
  compositeShape.printInfo();

  std::cout << "Remove shapes which have index 2 and 3\n";
  compositeShape.remove(3);
  compositeShape.remove(2);
  compositeShape.printInfo();

  std::cout << "Move to {-4,7}\n";
  compositeShape.move({-4, 7});
  compositeShape.printInfo();

  std::cout << "Get shape which has index 0 and print information about it:\n";
  zybkin::Shape * shape = compositeShape[0];
  shape->printInfo();

  std::cout << "Scale composite shape in 0,8 times\n";
  compositeShape.scale(0.8);
  compositeShape.printInfo();

  return 0;
}
