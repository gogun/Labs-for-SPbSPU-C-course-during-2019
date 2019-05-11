#include <iostream>
#include <cassert>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void actions(Shape *usingShape)
{
  assert(usingShape != nullptr);
  usingShape->printInfo();
  std::cout << "Move shape for 5 right, 6 up" << std::endl;
  usingShape->move(5, 6);
  usingShape->printInfo();
  std::cout << "Move shape to (4,7)" << std::endl;
  usingShape->move({4, 7});
  usingShape->printInfo();
}

int main()
{
  Rectangle rectangle(10.0, 5.0, {15.0, 15.0});
  Circle circle(2.5, {3.14, 2.71});
  Triangle triangle({10, 10}, {10, 30}, {40, 30});
  actions(&circle);
  actions(&rectangle);
  actions(&triangle);
  return 0;
}
