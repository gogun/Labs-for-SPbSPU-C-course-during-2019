#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"


void showRectangle(rectangle_t rect)
{
  std::cout << "width: " << rect.width << ", height: " << rect.height;
  std::cout << ", x: " << rect.pos.x << ", y: " << rect.pos.y;
  std::cout << std::endl;
}

void show(const Shape & shape)
{
  std::cout << __LINE__ << ": " << shape.getArea() << std::endl;
  showRectangle(shape.getFrameRect());
}

int main()
{
  Rectangle rect (10.0, 5.0, {.x = 15.0, .y = 15.0});
  show(rect);
  rect.move({.x = -10, .y =-5});
  show(rect);
    
  Circle circle (5.0, {.x = 1.0, .y = 2.0 });
  show(circle);
    
  return 0;
}
