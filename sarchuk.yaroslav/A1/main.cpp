#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main() {
  Circle circle({1,0},2);
  Rectangle rectangle({2, 5}, 4, 4);
  Shape * shape[2] = {&circle, &rectangle};
  std::cout << "New circle:\n";
  shape[0]->writeInfo();
  Rectangle rect(shape[0]->getFrameRect());
  std::cout << "Rectangle around circle\n";
  rect.writeInfo();
  std::cout << "Move to point 8,8\n";
  shape[0]->move({8, 8});
  shape[0]->writeInfo();
  std::cout << "Move to 2,2\n";
  shape[0]->move(2, 2);
  shape[0]->writeInfo();
  std::cout << "New Rectangle\n";
  shape[1]->writeInfo();
  std::cout << "Move to point 8,8\n";
  shape[1]->move({8, 8});
  shape[1]->writeInfo();
  std::cout << "Move to 2,2\n";
  shape[1]->move(2, 2);
  shape[1]->writeInfo();

  return 0;
}
