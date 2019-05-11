#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

int main()
{
  std::cout << "Create a circle with a radius of 1 at the origin." << std::endl;
  kvashnin::Circle cir = kvashnin::Circle({0, 0}, 1);

  std::cout << "Using polymorphism and learn data about the object." << std::endl;
  kvashnin::Shape *figure = &cir;
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Move the object and check the data about the object." << std::endl;
  figure->move(15, 10);
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Set new coordinates for the object." << std::endl;
  figure->move({20, 15});
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Scale object." << std::endl;
  figure->scale(2);
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Create a rectangle with dimensions {2, 2} in coordinates {10, 20}." << std::endl;
  kvashnin::Rectangle rec = kvashnin::Rectangle({2, 2}, 10, 20);

  figure = &rec;
  std::cout << "Learn data about the object." << std::endl;
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Move the object." << std::endl;
  figure->move({10, 10});
  std::cout << "Check the new coordinates." << std::endl;
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Move the object." << std::endl;
  figure->move(2, 4);
  std::cout << "Check the new coordinates." << std::endl;
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Scale object." << std::endl;
  figure->scale(2);
  figure->printInfo();
  std::cout << std::endl;

  std::cout << "Create an empty object and see this." << std::endl;
  kvashnin::CompositeShape comShp;
  comShp.printInfo();
  std::cout << std::endl;

  std::cout << "Add circle." << std::endl;
  comShp.add(&cir);
  comShp.printInfo();
  std::cout << std::endl;

  std::cout << "Add rectangle." << std::endl;
  comShp.add(&rec);
  comShp.printInfo();
  std::cout << std::endl;

  std::cout << "Get circle." << std::endl;
  comShp[0]->printInfo();
  std::cout << std::endl;

  std::cout << "Scale object." << std::endl;
  comShp.scale(2);
  comShp.printInfo();
  std::cout << std::endl;

  std::cout << "Remove rectangle." << std::endl;
  comShp.remove(1);
  comShp.printInfo();
  std::cout << std::endl;


  return 0;
}
