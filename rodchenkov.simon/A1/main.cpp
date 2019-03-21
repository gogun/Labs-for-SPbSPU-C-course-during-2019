#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

void testShape(Shape* s, const point_t& p);

int main()
{
  Shape* shapes[2];
  try {
    shapes[0] = new Rectangle{{10, 10}, 20, 40};
    shapes[1] = new Circle{{100, 100}, 10};
    for (auto& sh : shapes) {
      testShape(sh, {5, 5});
    }
    delete shapes[0];
    delete shapes[1];
  }
  catch (std::invalid_argument& exp) {
    std::cerr << exp.what();
    delete shapes[0];
    delete shapes[1];
    return 1;
  }
  catch (...) {
    std::cerr << "Internal error.\n";
    delete shapes[0];
    delete shapes[1];
    return 2;
  }
  return 0;
}

void testShape(Shape* s, const point_t& p)
{
  std::cout << "Before moving :\n";
  s->printData(std::cout);
  s->move(p);
  std::cout << "After moving to (" << p.x << ", " << p.y << ") :\n";
  s->printData(std::cout);
}
