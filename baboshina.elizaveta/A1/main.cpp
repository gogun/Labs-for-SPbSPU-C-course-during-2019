#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void test(Shape * shape)
{
  assert(shape != nullptr);
  shape->getInfo();
  std::cout << "The area of shape is: " << shape->getArea() << std::endl;
  std::cout << "Width of frame rectangle is: " << shape->getFrameRect().width << std::endl;
  std::cout << "Height of frame rectangle is: " << shape->getFrameRect().height << std::endl;
  shape->move({1, 1});
  shape->getInfo();
  shape->move(4, 5);
  shape->getInfo();
}

int main()
{
  Circle circle({3, 4}, 6);
  std::cout << "\n---Information about circle---" << std::endl;
  test(&circle);

  Rectangle rectangle({5, 5}, 20, 5);
  std::cout << "\n---Information about rectangle---" << std::endl;
  test(&rectangle);

  Triangle triangle({1, 1}, {3, 4}, {-4, 4});
  std::cout << "\n---Information about triangle---" << std::endl;
  test(&triangle);
  
  return 0;
}
