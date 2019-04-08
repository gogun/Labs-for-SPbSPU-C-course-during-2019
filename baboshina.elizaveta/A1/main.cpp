#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void test(Shape &shape)
{
  shape.getInfo();
  std::cout << "The area of shape is: " << shape.getArea() << std::endl;
  std::cout << "Width of frame rectangle is: " << shape.getFrameRect().width << std::endl;
  std::cout << "Height of frame rectangle is: " << shape.getFrameRect().height << std::endl;
  shape.move({ 1,1 });
  shape.getInfo();
  shape.move(4, 5);
  shape.getInfo();
}

int main()
{
  Circle circle({ 3,4 }, 6);
  std::cout << "\n---Information about circle---" << std::endl;
  test(circle);

  Rectangle rectangle({ 5,5 }, 20, 5);
  std::cout << "\n---Information about rectangle---" << std::endl;
  test(rectangle);
  return 0;
}
