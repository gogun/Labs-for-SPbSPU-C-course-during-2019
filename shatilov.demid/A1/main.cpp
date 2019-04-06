#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void show(rectangle_t rect)
{
  std::cout << "width = " << rect.width;
  std::cout << ", height = " << rect.height<<std::endl;
  std::cout << "x = " << rect.pos.x;
  std::cout << ", y = " << rect.pos.y;
  std::cout << std::endl << std::endl;
}

void showArea(const Shape & shape)
{
  std::cout << "Area = " << shape.getArea() << std::endl;
  show(shape.getFrameRect());
}
void showPoint(const Shape & shape)
{
  std::cout << "x = " << shape.getFrameRect().pos.x;
  std::cout << ", y = " << shape.getFrameRect().pos.y << std::endl <<std::endl;
}
int main()
{
  Rectangle rect( 25.0, 7.0, {13.0, 13.0});
  showArea(rect);
  rect.move({-10, -5});
  showPoint(rect);

  Circle circle (5.0, {1.0, 2.0 });
  showArea(circle);
  circle.move({10,5});
  showPoint(circle);

  return 0;
}

