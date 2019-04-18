#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Circle shape_1({1.0, 2.0}, 5.0);
  Shape *cir = &shape_1;
  std::cout << "Circle:" << std::endl;

  cir->printInformation();

  cir->move({3.0, 4.0});
  std::cout << "Move to the point (" << cir->getPosition().x << ", " << cir->getPosition().y << ")" << std::endl;

  cir->move(7.0, 6.0);
  std::cout << "Move on (" << cir->getPosition().x << ", " << cir->getPosition().y << ")" << std::endl << std::endl;

  Rectangle shape_2({1.0, 2.0}, 5.0, 8.0);
  Shape *rect = &shape_2;
  std::cout << "Rectangle:" << std::endl;

  rect->printInformation();

  rect->move({3.0, 4.0});
  std::cout << "Move to the point (" << rect->getPosition().x << ", " << rect->getPosition().y << ")" << std::endl;

  rect->move(7.0, 6.0);
  std::cout << "Move on (" << rect->getPosition().x << ", " << rect->getPosition().y << ")" << std::endl << std::endl;

  Triangle shape_3({0.0, 0.0}, {0.0, 3.0}, {4.0, 0.0});
  Shape *tri = &shape_3;
  std::cout << "Triangle:" << std::endl;

  tri->printInformation();

  tri->move({6.0, 11.0});
  std::cout << "Move to the point (" << tri->getPosition().x << ", " << tri->getPosition().y << ")" << std::endl;

  tri->move(2.0, 5.0);
  std::cout << "Move on (" << tri->getPosition().x << ", " << tri->getPosition().y << ")" << std::endl;

  return 0;
}
