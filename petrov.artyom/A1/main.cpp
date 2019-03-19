#include <iostream>
#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{

  point_t centre = point_t { 20, 40 };

  Rectangle polymorphicRectangle = Rectangle(centre, 100, 100);
  Shape * shape = &polymorphicRectangle;
  std::cout << "Area of rectangle 100*100 is " << shape->getArea() << std::endl;

  Circle polymorphicCircle(centre, 10);
  shape = &polymorphicCircle;
  std::cout << "Area of circle of raidus 10 is " << shape->getArea() << std::endl;

  auto startingFrame = shape->getFrameRect();
  shape->move(50, 40);
  auto finishFrame = shape->getFrameRect();
  std::cout << "Shape frame moved for ("
    << finishFrame.pos.x - startingFrame.pos.x << ";"
    << finishFrame.pos.y - startingFrame.pos.y  << ") unit points" << std::endl;

  centre = point_t { 30, 50 };
  Circle circle(centre, 20);
  std::cout << "Area of circle of centre ("
    << circle.getCentre().x << ";" << circle.getCentre().y
    << ") and raidus " << circle.getRadius()
    << " is " << circle.getArea() << std::endl;

  rectangle_t rect { 40, 40, centre };
  Rectangle rectangle(polymorphicRectangle);
  startingFrame = rectangle.getFrameRect();
  rectangle.move(point_t { 100, 200 });
  finishFrame = rectangle.getFrameRect();
  std::cout << "Rectangle frame moved for ("
    << finishFrame.pos.x - startingFrame.pos.x << ";"
    << finishFrame.pos.y - startingFrame.pos.y  << ") unit points" << std::endl;

  point_t point1 { 20, 20 };
  point_t point2 { 30, 12 };
  point_t point3 { 43, 55 };
  Triangle triangle(point1, point2, point3);
  std::cout << "Centre of triangle is ("
    << triangle.getCentre().x<< ";"
    << triangle.getCentre().y << ")" << std::endl;

  try
  {
    Triangle invalidTriangle(centre, centre, centre);
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << std::endl;
    return 2;
  }

  return 0;
}