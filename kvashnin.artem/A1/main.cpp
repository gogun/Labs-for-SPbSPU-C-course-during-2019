#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main() {
  std::cout << "Create a circle with a radius of 1 at the origin." << std::endl;
  Circle cir = Circle({0, 0}, 1);

  std::cout << "Using polymorphism and learn data about the object." << std::endl;
  Shape *shp = &cir;
  shp->printInfo();
  std::cout << std::endl;


  std::cout << "Move the object and check the data about the object." << std::endl;
  shp->move(15, 10);
  cir.printInfo();
  std::cout << std::endl;

  std::cout << "Set new coordinates for the object." << std::endl;
  shp->move({20, 15});
  cir.printInfo();
  std::cout << std::endl;

  std::cout << "Create a rectangle with dimensions {2, 2} in coordinates {10, 20}." << std::endl;
  Rectangle rec = Rectangle({2, 2}, 10, 20);

  std::cout << "Learn data about the object." << std::endl;
  rec.printInfo();
  std::cout << std::endl;

  std::cout << "Move the object." << std::endl;
  rec.move({10, 10});

  std::cout << "Check the new coordinates." << std::endl;
  rec.printInfo();
  std::cout << std::endl;
  
  return 0;
}
