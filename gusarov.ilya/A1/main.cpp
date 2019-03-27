#include "rectangle.hpp"
#include "circle.hpp"
#include "shape.hpp"
#include <iostream>

int main()
{
  //прямоугольник
  Rectangle rec({3,5},1,4);
  Shape *shape = &rec;
  shape->printInfo();
  std::cout << "Area of rectangle is " << shape->getArea() <<'\n';
  shape->move(2,3);
  shape->move({-2,-3});
  //Вывод данных после смещения
  shape->printInfo();
  //круг
  Circle cir({1,4}, 6);
  shape = &cir;
  shape->printInfo();
  std::cout << "Area of circle is " << shape->getArea() <<'\n';
  shape->move(2,1);
  shape->move({4,-3});
  //Вывод данных после смещения
  shape->printInfo();

  return 0;
}
