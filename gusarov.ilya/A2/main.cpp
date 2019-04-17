#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "shape.hpp"

int main()
{
  //прямоугольник
  gusarov::Rectangle rec({3,5},1,4);
  gusarov::Shape *shape = &rec;
  shape->printInfo();
  std::cout << "Area of rectangle is " << shape->getArea() << '\n';
  shape->move(2,3);
  shape->move({-2,-3});
  shape->scale(2);
  //Вывод данных после смещения и масштабирования
  shape->printInfo();
  //окружность
  gusarov::Circle cir({1,4}, 2);
  shape = &cir;
  shape->printInfo();
  std::cout << "Area of circle is " << shape->getArea() << '\n';
  shape->move(2,1);
  shape->move({4,-3});
  shape->scale(3);
  //Вывод данных после смещения и масштабирования
  shape->printInfo();

  return 0;
}
