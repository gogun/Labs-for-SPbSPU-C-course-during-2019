#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

using namespace std;

int main() {
  Circle circle({0, 0}, 3);
  Shape *shape = &circle;
  cout << "New circle:\n";
  shape->writeInfo();

  Rectangle rect(shape->getFrameRect());
  cout << "Rectangle around circle\n";
  rect.writeInfo();

  cout << "Move to point 8,8\n";
  shape->move({8, 8});
  shape->writeInfo();
  cout << "Move to 2,2\n";
  shape->move(2, 2);
  shape->writeInfo();

  cout << "New Rectangle\n";
  shape = new Rectangle({2, 5}, 4, 4);
  shape->writeInfo();

  cout << "Move to point 8,8\n";
  shape->move({8, 8});
  shape->writeInfo();
  cout << "Move to 2,2\n";
  shape->move(2, 2);
  shape->writeInfo();

  delete[] shape;
  cout << "New Triangle\n";
  shape = new Triangle({0, 0}, {0, 3}, {9, 0});
  shape->writeInfo();

  cout << "Move to point 8,8\n";
  shape->move({8, 8});
  shape->writeInfo();
  cout << "Move to 2,2\n";
  shape->move(2, 2);
  shape->writeInfo();
  delete[] shape;
  shape = new Rectangle(shape->getFrameRect());
  cout << "Rectangle around triangle\n";
  shape->writeInfo();

  delete[] shape;

  return 0;
}
