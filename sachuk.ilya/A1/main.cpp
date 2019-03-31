#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle c1({2,3},10);//Создание круга
  Shape *s1 = &c1;
  s1->printInfo();
  s1->move({7,8});//Перемещение в точку
  s1->printInfo();
  s1->move(4,5);//Смещение по осям
  s1->printInfo();
  Rectangle r1({5,8},10,14);//Создание прямоугольника
  s1=&r1;
  s1->printInfo();
  s1->move({8,3});//Перемещение в точку
  s1->printInfo();
  s1->move(10,23);//Перемещение по осям
  s1->printInfo();
  return 0;
}
