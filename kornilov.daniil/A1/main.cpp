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
  //setting dot(pos) coordinates
  pos.x = 0;
  pos.y = 0;
  //setting width and height of rectangle
  double width = 50;
  double height = 40;
  //setting radius of circle
  double radius = 10;
  //creating circle and writing info
  Circle circle(pos, radius);
  rect = circle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << circle.getArea() << std::endl;
  //creating rectangle and writing info
  Rectangle rectangle({pos, width, height});
  rect = rectangle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << rectangle.getArea() << std::endl;
  //moving circle and rectangle
  rectangle.move(10, 10);
  circle.move(10, 10);
  //writing info about circle
  rect = circle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << circle.getArea() << std::endl;
  //writing info about rectangle
  rect = rectangle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << rectangle.getArea() << std::endl;
  //new coordinates of dot(pos)
  pos.x = 20;
  pos.y = 50;
  //moving rectangle to dot(pos)
  rectangle.move(pos);
  //demonstrating polymorphism
  Shape &shape1 = rectangle;
  rect = shape1.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << shape1.getArea() << std::endl;
  //moving rectangle to another position and writing info
  shape1.move(10, 20);
  rect = shape1.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of rectangle: " << shape1.getArea() << std::endl;
  //moving circle to dot(pos) and writing info
  circle.move(pos);
  Shape &shape2 = circle;
  rect = shape2.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << shape2.getArea() << std::endl;
  //moving circle to another position and writing info
  shape2.move(10, 20);
  rect = shape2.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << shape2.getArea() << std::endl;

  return 0;
}
