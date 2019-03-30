#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  //Rectangle
  Rectangle rectangle({5, 5}, 10, 5);
  point_t pos = rectangle.getPosition();
  std::cout << "Position of rectangle: x = " << pos.x << ", y = " << pos.y << "\n";
  rectangle.move({15, 50});
  pos = rectangle.getPosition();
  std::cout << "New position of rectangle: x = " << pos.x << ", y = " << pos.y << "\n";
  rectangle.move(25, 10); // x = 15 + 25 = 40, y = 50 + 10 = 60
  pos = rectangle.getPosition();
  std::cout << "New position of rectangle: x = " << pos.x << ", y = " << pos.y << "\n";
  double areaOfRectangle = rectangle.getArea(); // 10 * 5 = 50;
  std::cout << "Area of this rectangle is " << areaOfRectangle << "\n";
  rectangle_t frameRect = rectangle.getFrameRect(); // width = 10, height = 5, pos = 40, 60
  std::cout << "Width of frame = " << frameRect.width << ", height = " << frameRect.height << "\n";
  std::cout << "Position of frame: x = " << frameRect.pos.x << ", y = " << frameRect.pos.y << "\n\n";

  //Circle
  Circle circle({0, 0}, 5);
  pos = circle.getPosition();
  std::cout << "Position of circle: x = " << pos.x << ", y = " << pos.y << "\n";
  circle.move({5, 5});
  pos = circle.getPosition();
  std::cout << "New position of circle: x = " << pos.x << ", y = " << pos.y << "\n";
  circle.move(25, 10); // x = 5 + 25 = 30, y = 5 + 10 = 15;
  pos = circle.getPosition();
  std::cout << "New position of circle: x = " << pos.x << ", y = " << pos.y << "\n";
  double areaOfCircle = circle.getArea();
  std::cout << "Area of this circle is " << areaOfCircle << "\n";
  frameRect = circle.getFrameRect(); // width = 10, height = 10, pos = 30, 15
  std::cout << "Width of frame = " << frameRect.width << ", height = " << frameRect.height << "\n";
  std::cout << "Position of frame: x = " << frameRect.pos.x << ", y = " << frameRect.pos.y << "\n\n";

  //we have 2 objects : circle({30, 15}, 5) and rectangle({40, 60}, 10 , 5)
  Shape *shape = &circle;
  //Now using *shape, we will work with circle
  std::cout << "Position of shape: x = " << shape->getPosition().x << " y = " << shape->getPosition().y << "\n";
  std::cout << "Area of this shape = " << shape->getArea() << "\n";
  //Now moving this shape from {30, 15} to {50, 65}
  shape->move({50, 65});
  std::cout << "Position of shape: x = " << shape->getPosition().x << " y = " << shape->getPosition().y << "\n";
  //Let's move this shape by dx on -30 and by dy on 15
  shape->move(-30, 15);
  std::cout << "Position of shape: x = " << shape->getPosition().x << " y = " << shape->getPosition().y << "\n";
  frameRect = shape->getFrameRect();
  std::cout << "Width of frame = " << frameRect.width << ", height = " << frameRect.height << "\n";
  std::cout << "Position of frame: x = " << frameRect.pos.x << ", y = " << frameRect.pos.y << "\n\n";
  //we have got circle's frame rectangle with position 20,80 (we changed it)
  //Now work with rectangle
  shape = &rectangle;
  std::cout << "Position of shape: x = " << shape->getPosition().x << " y = " << shape->getPosition().y << "\n";
  std::cout << "Area of this shape = " << shape->getArea() << "\n";
  //Now moving this shape from {40, 60} to {100, 100}
  shape->move({100, 100});
  std::cout << "Position of shape: x = " << shape->getPosition().x << " y = " << shape->getPosition().y << "\n";
  //Let's move this shape by dx on -50 and by dy on -15
  shape->move(-50, -15);
  std::cout << "Position of shape: x = " << shape->getPosition().x << " y = " << shape->getPosition().y << "\n";
  frameRect = shape->getFrameRect();
  std::cout << "Width of frame = " << frameRect.width << ", height = " << frameRect.height << "\n";
  std::cout << "Position of frame: x = " << frameRect.pos.x << ", y = " << frameRect.pos.y << "\n\n";
}

