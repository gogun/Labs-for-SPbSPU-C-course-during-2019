#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  /*Прямоугольник*/
  shreder::Rectangle rect({{1,5},5,4});
  shreder::Shape * shapepoint = & rect;
  std::cout << "Creating of rectangle...\n";
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Moving to the point with coordinates(7,1)\n";
  shapepoint->move({7,1});
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Moving along abscissa for 4 and along ordinate for 6\n";
  shapepoint->move(4,6);
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Zoom scale of rectangle in two times and get new parameters\n";
  shapepoint->scale(2);
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Ready!\n";
  std::cout << "\n";

  /*Круг*/
  shreder::Circle circl({{5,5},4});
  shapepoint = & circl;
  std::cout << "Creating of circle...\n";
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Moving to the point with coordinates(6,9)\n";
  shapepoint->move({6,9});
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Moving along abscissa for -1 and along ordinate for -2\n";
  shapepoint->move(-1,-2);
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Zoom scale of circle in four times and get new parameters\n";
  shapepoint->scale(4);
  shapepoint->printInf();
  std::cout << "\n";
  std::cout << "Ready!\n";
  std::cout << "\n";

  return 0;
}
