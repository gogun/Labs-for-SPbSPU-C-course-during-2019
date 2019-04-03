#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  //Создание круга и прямоугольника с помощью двух разных конструкторов:
  //а) центр задается через координаты
  //б) центр задается через точку
  Circle circle1(5,5,5);
  Rectangle rectangle1({2,2},20,30);
  circle1.printInfo();
  rectangle1.printInfo();

  //Демонстрация перемещения фигур
  Shape * shCircle = &circle1;
  shCircle->move({10,10});

  Shape * shRect = &rectangle1;
  shRect->move({10,0});

  std::cout << "After moving " << std::endl;
  shCircle->printInfo();
  shRect->printInfo();

  //Получение ограничивающего прямоугольника для круга
  const rectangle_t boundedRectCircle = shCircle->getFrameRect();
  std::cout << std::fixed << "Bounded rectangle for Circle has " << std::endl
    << "X (center): " << boundedRectCircle.pos.x <<std::endl
      << "Y (center): " << boundedRectCircle.pos.y <<std::endl
        << "Width: " << boundedRectCircle.width <<std::endl
          << "Height: " << boundedRectCircle.heigh << std::endl << std::endl;

    //Получение ограничивающего прямоугольника для прямоугольника
  const rectangle_t boundedRectRectangle = shRect->getFrameRect();
  std::cout << std::fixed << "Bounded rectangle for Rectangle has" << std::endl
    << "X (center): " << boundedRectRectangle.pos.x <<std::endl
      << "Y (center): " << boundedRectRectangle.pos.y <<std::endl
        << "Width: " << boundedRectRectangle.width <<std::endl
          << "Height: " << boundedRectRectangle.heigh << std::endl;

  return 0;
}
