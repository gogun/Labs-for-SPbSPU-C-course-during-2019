#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t centre = point_t { 20, 40 };


  Rectangle rectangle = Rectangle(centre, 100, 100);
  Shape * shape = &rectangle;
  std::cout << "Area of rectangle 100*100 is " << shape->getArea() << std::endl;


  Circle circle(centre, 10);
  shape = &circle;
  std::cout << "Area of circle of raidus 10 is " << shape->getArea() << std::endl;


  auto /* rectangle_t */ startingFrame = shape->getFrameRect();
  shape->move(50, 40);
  auto /* rectangle_t */ finishFrame = shape->getFrameRect();
  std::cout << "Shape frame moved for ("
            << finishFrame.pos.x - startingFrame.pos.x << ";"
            << finishFrame.pos.y - startingFrame.pos.y  << ") unit points" << std::endl;


  centre = point_t { 30, 50 };
  circle = Circle(centre, 20);
  std::cout << "Area of circle with centre ("
            << circle.getCentre().x << ";" << circle.getCentre().y
            << ") and raidus " << circle.getRadius()
            << " is " << circle.getArea() << std::endl;

  rectangle = Rectangle(centre, 40, 40);
  std::cout << "Area of rectangle with centre ("
            << rectangle.getCentre().x << ";" << rectangle.getCentre().y
            << "), width " << rectangle.getWidth() << " and height " << rectangle.getHeight()
            << "is " << rectangle.getArea() << std::endl;


  Rectangle rectangleToMove(rectangle);
  startingFrame = rectangleToMove.getFrameRect();
  rectangleToMove.move(point_t { 100, 200 });
  finishFrame = rectangleToMove.getFrameRect();
  std::cout << "Rectangle frame moved for ("
            << finishFrame.pos.x - startingFrame.pos.x << ";"
            << finishFrame.pos.y - startingFrame.pos.y  << ") unit points" << std::endl;

  return 0;
}
