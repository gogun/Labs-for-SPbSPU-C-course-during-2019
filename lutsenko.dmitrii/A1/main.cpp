#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
	
void showRectangle(rectangle_t rect)
{
  std::cout << "width: " << rect.width << ", height: " << rect.height;
  std::cout << ", x: " << rect.pos.x << ", y: " << rect.pos.y << "\n";
}

void show(const Shape & shape)
{
  showRectangle(shape.getFrameRect());
  std::cout << "Area = " << shape.getArea() << "\n";
}

int main()
{
  std::cout << "        Demonstrate Rectangle" << "\n";
  Rectangle rect({10.0, 15.0, 20.0, 25.0});
  show(rect);
  rect.move({100.0, 200.0});
  show(rect);
  rect.move(10.0, 20.0);
  show(rect);
  Rectangle rect2({6.0, 9.0, 7.0, 7.0});
  show(rect2);
  std::cout << "        Demonstrate Circle" << "\n";
  Circle circle(10.0, {1.0, 2.0});
  show(circle);
  circle.move({5.0, 7.0});
  show(circle);
  circle.move(10.0, 10.0);
  show(circle);
  Circle circle2(5.0, {1.0, 1.0});
  show(circle2);
  return 0;
};