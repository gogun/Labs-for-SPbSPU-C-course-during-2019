#include <iostream>
#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

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

  Rectangle rectangle(polymorphicRectangle);
  startingFrame = rectangle.getFrameRect();
  rectangle.move(point_t { 100, 200 });
  finishFrame = rectangle.getFrameRect();
  std::cout << "Rectangle frame moved for ("
            << finishFrame.pos.x - startingFrame.pos.x << ";"
            << finishFrame.pos.y - startingFrame.pos.y  << ") unit points" << std::endl;

  return 0;
}
