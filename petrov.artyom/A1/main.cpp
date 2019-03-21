#include <iostream>
#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t centre = point_t { 20, 40 };

  Rectangle rectangle = Rectangle(centre, 100, 100);
  Shape * shape = &rectangle;
  std::cout << "Area of rectangle 100*100 is " << shape->getArea() << std::endl;

  Circle polymorphicCircle(centre, 10);
  shape = &polymorphicCircle;
  std::cout << "Area of circle of raidus 10 is " << shape->getArea() << std::endl;

  auto /* rectangle_t */ startingFrame = shape->getFrameRect();
  shape->move(50, 40);
  auto /* rectangle_t */ finishFrame = shape->getFrameRect();
  std::cout << "Shape frame moved for ("
            << finishFrame.pos.x - startingFrame.pos.x << ";"
            << finishFrame.pos.y - startingFrame.pos.y  << ") unit points" << std::endl;

  centre = point_t { 30, 50 };
  Circle circle(centre, 20);
  std::cout << "Area of circle of centre ("
            << circle.getCentre().x << ";" << circle.getCentre().y
            << ") and raidus " << circle.getRadius()
            << " is " << circle.getArea() << std::endl;

  Rectangle rectangleToMove(rectangle);
  startingFrame = rectangleToMove.getFrameRect();
  rectangleToMove.move(point_t { 100, 200 });
  finishFrame = rectangleToMove.getFrameRect();
  std::cout << "Rectangle frame moved for ("
            << finishFrame.pos.x - startingFrame.pos.x << ";"
            << finishFrame.pos.y - startingFrame.pos.y  << ") unit points" << std::endl;

  try
  {
    Circle invalidCirce(centre, -5);
  }
  catch (std::invalid_argument& e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    Rectangle invalidWidthRectangle(centre, -5, 9);
  }
  catch (std::invalid_argument& e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    Rectangle invalidHeightRectangle(centre, 5, -9);
  }
  catch (std::invalid_argument& e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
