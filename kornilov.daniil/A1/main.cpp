#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void writeFrameRectInfo(rectangle_t &rect)
{
  std::cout << "Frame Rectangle: "
            << "Width: " << rect.width << " Height: " << rect.height
            << " Centre: " << '(' << rect.pos.x << ", " << rect.pos.y << ')'
            << std::endl;
}

int main()
{
  rectangle_t rect;
  point_t pos;
  pos.x = 0;
  pos.y = 0;
  double width = 10;
  double height = 10;
  double radius = 10;
  Circle newCircle(radius, pos);
  rect = newCircle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << newCircle.getArea() << std::endl;
  Rectangle newRectangle({ width, height, pos });
  rect = newRectangle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << newRectangle.getArea() << std::endl;
  newRectangle.move(10, 10);
  newCircle.move(10, 10);
  rect = newCircle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << newCircle.getArea() << std::endl;
  rect = newRectangle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << newRectangle.getArea() << std::endl;
  pos.x = 20;
  newRectangle.move(pos);
  Shape *r = &newRectangle;
  rect = r->getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << r->getArea() << std::endl;
  r->move(10, 20);
  rect = r->getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << r->getArea() << std::endl;
  newCircle.move(pos);
  Shape *c = &newCircle;
  rect = c->getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << c->getArea() << std::endl;
  c->move(10, 20);
  rect = c->getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << c->getArea() << std::endl;
  return 0;
}
