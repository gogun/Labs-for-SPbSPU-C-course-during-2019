#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Shape* shapes[2];
  try {
    shapes[0] = new Rectangle{{10, 10}, 20, 40};
    shapes[1] = new Circle{{100, 100}, 10};
    for (auto& sh : shapes) {
      sh->printData(std::cout);
      sh->move({5, 5});
      sh->printData(std::cout);
    }
    delete[] shapes;
  }
  catch (std::invalid_argument& exp) {
    std::cerr << exp.what();
    delete[] shapes;
    return 1;
  }
  catch (...) {
    std::cerr << "Internal error.\n";
    delete[] shapes;
    return 2;
  }
  return 0;
}
