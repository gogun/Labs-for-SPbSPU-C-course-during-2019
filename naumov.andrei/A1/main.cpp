#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Rectangle rectangle_test({ 40,20 },11.5,10);
  Circle circle_test({ 20,40 },12);

  std::cout << "rectangle area: "<<rectangle_test.getArea() << std::endl;
  std::cout << "rectangle's frame rect: w " << (rectangle_test.getFrameRect()).width
    << " h " << (rectangle_test.getFrameRect()).height << std::endl;
  std::cout << "rectangle`s centre: x" << rectangle_test.getCentre().x
    << " y " << rectangle_test.getCentre().y << std::endl;

  std::cout << "circle area: " << circle_test.getArea() << std::endl;
  std::cout << "circle`s frame rect: w" << (circle_test.getFrameRect()).width
    << " h " <<(circle_test.getFrameRect()).height << std::endl;
  std::cout << "circle`s centre: x" << circle_test.getCentre().x
    << " y " << circle_test.getCentre().y << std::endl;

  rectangle_test.setHeight(2);
  rectangle_test.setWidth(2);
  circle_test.setRadius(1);
  rectangle_test.move(100,100);
  circle_test.move({35,44});
  Shape * prectangle = &rectangle_test;
  Shape * pcircle = &circle_test;
  std::cout << "-----------------------------" << std::endl;

  std::cout << "new rectangle area: " << prectangle->getArea() << std::endl;
  std::cout << "new rectangle's frame rect: w " << (prectangle->getFrameRect()).width
    << " h " << (prectangle->getFrameRect()).height << std::endl;
  std::cout << "new rectangle`s centre: x" << prectangle->getCentre().x
    << " y " << prectangle->getCentre().y << std::endl;

  std::cout << "new circle area: " << pcircle->getArea() << std::endl;
  std::cout << "new circle`s frame rect: w" << (pcircle->getFrameRect()).width
    << " h " << (pcircle->getFrameRect()).height << std::endl;
  std::cout << "new circle`s centre: x" << pcircle->getCentre().x
    << " y " << pcircle->getCentre().y << std::endl;

  return 0;
}
