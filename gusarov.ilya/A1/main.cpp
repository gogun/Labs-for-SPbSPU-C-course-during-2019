#include <iostream>
#include "rectangle.hpp"
#include "shape.hpp"
#include "base-types.hpp"

int main()
{
  Rectangle rec({3,5},1,4);
  rec.printInfo();
  std::cout << "Area of rectangle is " << rec.getArea() <<'\n';
  rec.move(2,3);
  rec.move({-2,-3});
  //Вывод данных после смещения
  rec.printInfo();
  return 0;
}
