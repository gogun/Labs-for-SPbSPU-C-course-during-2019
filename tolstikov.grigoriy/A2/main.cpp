#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfo(const tolstikov::Shape * shapePointer)
{
  if (!shapePointer) {
    throw std::invalid_argument("Pointer can't be null!");
  }
  tolstikov::rectangle_t frameRect = shapePointer->getFrameRect();
  std::cout << "Area is " << shapePointer->getArea() << ";\nCentre is [" << frameRect.pos.x << ", ";
  std::cout << frameRect.pos.y << "];\n";
  std::cout << "Width of frame rectangle is " << frameRect.width << ", height is " << frameRect.height << ";\n";
}

int main()
{
  std::cout << "--------------------Circle--------------------\n";
  tolstikov::Circle c({ 1, 2.4 }, 5); // Circle with centre at point [1, 2.4] and radius 5
  tolstikov::Shape * shape = &c;
  printInfo(shape);
  std::cout << "Radius is " << c.getRadius() << ";\n";

  shape->move(5, 0.6);  // Move by some value
  std::cout << "\nMove 1.1:\n";
  printInfo(shape);
  std::cout << "Radius is " << c.getRadius() << ";\n";

  shape->move({ -3, -1 }); // Move to the point
  std::cout << "\nMove 1.2:\n";
  printInfo(shape);
  std::cout << "Radius is " << c.getRadius() << ";\n";

  std::cout << "\nCircle scalling:\n";
  shape->scale(3);
  printInfo(shape);
  std::cout << "Radius is " << c.getRadius() << ";\n";

  std::cout << "\n-------------------RECTANGLE-------------------\n";
  tolstikov::Rectangle r({ 3, 2 }, 5, 4); // Rectangle with centre at point [3, 2], width 5 and heigh 4
  shape = &r;
  printInfo(shape);

  shape->move(31.5, 5); // Move by some value
  std::cout << "\nMove 2.1:\n";
  printInfo(shape);

  shape->move({ -11, 2 }); // Move to the point
  std::cout << "\nMove 2.2:\n";
  printInfo(shape);

  std::cout << "\nRectangle scalling:\n";
  shape->scale(4);
  printInfo(shape);

  std::cout << "\n--------------------SQUARE--------------------\n";
  tolstikov::Rectangle s({ 4, 15 }, 11); // Square with centre at point [4, 15] and side 11
  shape = &s;
  printInfo(shape);

  shape->move(0, 0); // Move by some value
  std::cout << "\nMove 3.1:\n";
  printInfo(shape);

  shape->move({ 0, 0 }); // Move to the point
  std::cout << "\nMove 3.2:\n";
  printInfo(shape);

  std::cout << "\nSquare scalling:\n";
  shape->scale(5);
  printInfo(shape);

  return 0;
}
