#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void writeFrameRectInfo(rectangle_t &rect)
{
  std::cout << "Frame Rectangle: " << "Width: " << rect.width << " Height: " << rect.height
            << " Centre: " << '(' << rect.pos.x << ", " << rect.pos.y << ')' << std::endl;
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

  try 
  {
    Rectangle newRectangle(width, height, 10, 20);
  }
  catch (const std::invalid_argument &param)
  {
    std::cout << param.what() << std::endl;
    return 1;
  }
  
  Rectangle newRectangle(width, height, 10, 20);

  try
  {
    Circle newCircle(radius, 0, 10);
  }
  catch (const std::invalid_argument &param)
  {
    std::cout << param.what() << std::endl;
    return 1;
  }

  Circle newCircle(radius, 10, 15);

  rect = newCircle.getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Area of circle: " << newCircle.getArea() << std::endl;
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
  
  newRectangle.move(pos);

  Shape *r = &newRectangle;
  rect = r->getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Using polymorphic method to get area of rectangle: " << r->getArea() << std::endl;
  
  newCircle.move(pos);

  Shape *c = &newCircle;
  rect = c->getFrameRect();
  writeFrameRectInfo(rect);
  std::cout << "Using polymorphic method to get area of circle: " << c->getArea() << std::endl;
  
  return 0;
}
