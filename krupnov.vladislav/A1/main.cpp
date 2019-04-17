#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include <iostream>
#include <cassert>



void getInfo(const Shape *shape1)
{
  shape1->getCenterInfo();
}

void showArea(const Shape *shape)
{
  assert((shape != nullptr) && ("shape parameter is invalid, nullptr"));
  std::cout << "Area: " << shape->getArea() << std::endl;
}

void showRectangle(rectangle_t rect)
{
  std::cout << "Rectangle:" << std::endl;
  std::cout << "width: " << rect.width << ", height: " << rect.height;
  std::cout << ", x: " << rect.pos.x << ", y: " << rect.pos.y;
  std::cout << std::endl;
}

int main()
{
  Circle circle({1, 1}, 9);
  circle.printInfo();
  circle.setRadius(7);

  point_t p = {-10, 2};
  circle.move(p);
  circle.move(12, -10);
  getInfo(&circle);

  Rectangle rect(p, 2, 9);
  rect.printInfo();
  rect.setWidth(12);
  rect.setHeight(0.5);
  rect.move({-9, 7});
  rect.move(3, -4);
  getInfo(&rect);

  Triangle triangle({1, 1}, {10, 2}, {3, 5});
  triangle.printInfo();
  showRectangle(triangle.getFrameRect());
  showArea(&triangle);
  triangle.move({5, 5});
  triangle.printInfo();
  showRectangle(triangle.getFrameRect());
  showArea(&triangle);
  return 0;
}
