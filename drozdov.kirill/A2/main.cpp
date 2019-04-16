#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

void printDataShape(const drozdov::Shape *shape);

int main()
{
  drozdov::Rectangle rect1(7.2, 5.7, {5, -2.4});
  std::cout << "Rectangle:" << "\n*******************";
  printDataShape(&rect1);

  const double dx = 2.5, dy = -4.1;
  rect1.move(dx, dy);
  std::cout << "\n===After move: + (" << dx << ';' << dy << ")===";
  rect1.printData();

  double coefficientScale = 2.0;
  rect1.scale(coefficientScale);
  std::cout << "=====After scale x" << coefficientScale << "=====";
  rect1.printData();

  std::cout << std::endl;
  //end rectangle

  drozdov::Circle circ1(5, {6, 7.2});
  std::cout << "Circle:" << "\n*******************";
  printDataShape(&circ1);

  const drozdov::point_t position = {-1.8, 2.4};
  circ1.move(position);
  std::cout << "\n===After move to (-1.8, 2.4)===";
  circ1.printData();

  coefficientScale = 4.0;
  circ1.scale(coefficientScale);
  std::cout << "=====After scale x" << coefficientScale << "=====";
  circ1.printData();

  std::cout << std::endl;
  //end circle
  return 0;
}

void printDataShape(const drozdov::Shape *shape)
{
  if (shape != nullptr) {
    shape->printData();
    std::cout << "\nArea: " << shape->getArea() << std::endl;

    drozdov::rectangle_t frameRect = shape->getFrameRect();

    std::cout << "***Frame Rectangle:";
    std::cout << "\nWidth: " << frameRect.width  << "\tHeight: " << frameRect.height;
    std::cout << "\nPosition: (" << frameRect.pos.x << ';' << frameRect.pos.y << ')' << std::endl;
  } else {
    throw std::invalid_argument("\nShape's pointer is null.");
  }
}
