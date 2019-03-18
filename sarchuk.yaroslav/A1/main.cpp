#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

int main() {

  Shape * shape[2];

  shape[0] = new Circle({0, 0}, 3);
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
  shape[1] = new Rectangle({2, 5}, 4, 4);
  shape[1]->writeInfo();
  std::cout << "Move to point 8,8\n";
  shape[1]->move({8, 8});
  shape[1]->writeInfo();
  std::cout << "Move to 2,2\n";
  shape[1]->move(2, 2);
  shape[1]->writeInfo();


  for (int i = 0; i < 2; ++i)
    delete shape[i];

  return 0;
}
