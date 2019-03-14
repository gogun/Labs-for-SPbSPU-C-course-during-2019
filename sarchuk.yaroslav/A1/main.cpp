#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"


int main() {

  Shape* shape[4];

  shape[0] = new Circle({0, 0}, 3);
  std::cout<< "New circle:\n";
  shape[0]->writeInfo();

  Rectangle rect(shape[0]->getFrameRect());
  std::cout<< "Rectangle around circle\n";
  rect.writeInfo();
  std::cout<< "Move to point 8,8\n";
  shape[0]->move({8, 8});
  shape[0]->writeInfo();
  std::cout<< "Move to 2,2\n";
  shape[0]->move(2, 2);
  shape[0]->writeInfo();

  std::cout<< "New Rectangle\n";
  shape[1] = new Rectangle({2, 5}, 4, 4);
  shape[1]->writeInfo();
  std::cout<< "Move to point 8,8\n";
  shape[1]->move({8, 8});
  shape[1]->writeInfo();
  std::cout<< "Move to 2,2\n";
  shape[1]->move(2, 2);
  shape[1]->writeInfo();

  std::cout<< "New Triangle\n";
  shape[2] = new Triangle({0, 0}, {0, 3}, {9, 0});
  shape[2]->writeInfo();

  std::cout<< "Move to point 8,8\n";
  shape[2]->move({8, 8});
  shape[2]->writeInfo();
  std::cout<< "Move to 2,2\n";
  shape[2]->move(2, 2);
  shape[2]->writeInfo();

  shape[3] = new Rectangle(shape[2]->getFrameRect());
  std::cout<< "Rectangle around triangle\n";
  shape[3]->writeInfo();


  for (int i = 0; i < 4; ++i)
    delete shape[i];


  return 0;
}
