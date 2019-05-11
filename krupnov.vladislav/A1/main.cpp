#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"

void printShapeInfo(const Shape *shape);
void printFrameRectangle(rectangle_t frameRect);

int main()
{
  Circle circle(9.0, {1.0, 1.0});
  printShapeInfo(&circle);

  double dx = 12.0;
  double dy = -10.0;
  circle.move(dx, dy);
  std::cout << "\nChange after shifting the circle to (" << dx << "; "<< dy << ").";
  circle.printInfo();

  Rectangle rectangle(2.0, 9.0, {-1.0, 3.0});
  printShapeInfo(&rectangle);

  dx = 3.0;
  dy = 4.0;
  rectangle.move(dx, dy);
  std::cout << "\nChange after shifting the rectangle to (" << dx << "; "<< dy << ").";
  circle.printInfo();

  Triangle triangle({1.0, 1.0}, {10.0, 2.0}, {3.0, 5.0});
  printShapeInfo(&triangle);

  const point_t newPos = {3.0, 2.0};
  triangle.move(newPos);
  std::cout << "\nChanges after moving the triangle to a new position (" << newPos.x << "; "<< newPos.y << ").";
  triangle.printInfo();

  return 0;
}

void printFrameRectangle(rectangle_t frameRect)
{
  std::cout << "\nFrame Rectangle";
  std::cout << "\nWidth: " << frameRect.width;
  std::cout << "\nHeight: " << frameRect.height;
  std::cout << "\nCenter: " << frameRect.pos.x << "; " << frameRect.pos.y;
}

void printShapeInfo(const Shape *shape)
{
  if (shape == nullptr) {
    throw std::invalid_argument("The specified shape's pointer is not valid.");
  }
  shape->printInfo();
  std::cout << "\nArea: " << shape->getArea() << std::endl;

  const rectangle_t frameRect = shape->getFrameRect();
  printFrameRectangle(frameRect);
}
