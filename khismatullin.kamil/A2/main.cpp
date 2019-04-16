#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  khismatullin::Rectangle rectangle({2, 4}, 7, 10);  //создание прямоугольника

  rectangle.show(); //вывод всех параметров прямоугольника
  std::cout << "\n{Moving}:\n";
  rectangle.move({-3.2, 3.3});  //перемещение по координатам и дальнейший вывод текущего положения
  std::cout << "-- to point {-3.2, 3.3} : (" << rectangle.getCenter().x << ", " << rectangle.getCenter().y << ")\n";
  rectangle.move(4.3, 2.2);  //перемещение по смещению и дальнейший вывод текущего положения
  std::cout << "-- by offset {4.3, 2.2} : (" << rectangle.getCenter().x << ", " << rectangle.getCenter().y << ")\n";

  std::cout << "___________________________\n";

  khismatullin::Circle circle({2, 4}, 5); //создание круга

  circle.show(); //вывод всех параметров круга
  std::cout << "\n{Moving}:\n";
  circle.move({3.2, 3.5}); //перемещение по координатам и дальнейший вывод текущего положения
  std::cout << "-- to point {3.2, 3.5}  : (" << circle.getCenter().x << ", " << circle.getCenter().y << ")\n";
  circle.move(3.8, 3.5); //перемещение по смещению и дальнейший вывод текущего положения
  std::cout << "-- by offset {3.8, 3.5} : (" << circle.getCenter().x << ", " << circle.getCenter().y << ")\n";

  std::cout << "___________________________\n";

  khismatullin::Shape *shapes[] = {&rectangle, &circle}; //полиморфное применение
  shapes[0]->move(6, 7); //перемещение прямоугольника сдвигом
  shapes[1]->move(5, 10); //перемещение круга сдвигом
  for (khismatullin::Shape *shape:shapes) {
    shape->show();
    std::cout << "___________________________\n";
  }

  return 0;
}
