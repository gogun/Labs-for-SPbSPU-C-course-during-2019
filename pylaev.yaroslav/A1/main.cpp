#include <iostream>
#include <stdexcept>
#include <cassert>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void exercisesAndPrintSpec(Shape *);

int main(int, char *[])
{
  //Rectangle
  std::cout << "----------Work with the rectangle\n";
  point_t center = {1.0, 8.0};
  try {
    Rectangle rectangle_(center, 5.0, 9.0);
    exercisesAndPrintSpec(&rectangle_);
  }
  catch (std::invalid_argument & err) {
    std::cerr << err.what();
  }

  std::cout << std::endl;
  //Circle
  std::cout << "----------Work with the circle\n";
  center = {10.0, 80.0};
  try {
    Circle circle_(center, 18.0);
    exercisesAndPrintSpec(&circle_);
  }
  catch (std::invalid_argument & err) {
    std::cerr << err.what();
  }

  std::cout << std::endl;
  //Triangle
  std::cout << "----------Work with the triangle\n";
  center = {100.0, 800.0};
  const int nTops = 3;
  double sides[nTops] = {8.544003745, 10.0, 3.0};
  try {
    Triangle triangle_(center, sides);
    exercisesAndPrintSpec(&triangle_);
  }
  catch(std::invalid_argument & err) {
    std::cerr << err.what();
  }

  return 0;
}

void exercisesAndPrintSpec(Shape * shapePtr)
{
  assert(shapePtr != nullptr);
  //exercises: two types of moving figure
  const double dx = 3.5;
  const double dy = 5.5;
  const point_t newPoint = {10.0, 10.0};

  shapePtr->printSpec();
  shapePtr->move(dx, dy);
  std::cout << "After moving by " << dx << "; " << dy << std::endl;
  shapePtr->printSpec();
  shapePtr->move(newPoint);
  std::cout << "After moving to the point (" << newPoint.x << "; " << newPoint.y << ")\n";
  shapePtr->printSpec();
}
