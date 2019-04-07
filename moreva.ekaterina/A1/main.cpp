#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  //Создание круга и прямоугольника с помощью двух разных конструкторов:
  //а) центр задается через координаты
  //б) центр задается через точку
  Circle circle1(5, 5, 5);
  Rectangle rectangle1({2, 2}, 20, 30);
  circle1.printInfo();
  rectangle1.printInfo();

  Shape * shape = &circle1;

  //Демонстрация перемещения фигуры
  //смещение в заданную точку
  shape->move({12, 12});
  std::cout << "After moving 1" << std::endl;
  shape->printInfo();

  //смещение центра
  shape->move(10, 10);
  std::cout << "After moving 2" << std::endl;
  shape->printInfo();

  //Получение ограничивающего квадрата для круга
  const rectangle_t boundedRectCircle = shape->getFrameRect();
  std::cout << "Bounded rectangle for Circle has " << std::endl
            << "X (center): " << boundedRectCircle.pos.x << std::endl
            << "Y (center): " << boundedRectCircle.pos.y << std::endl
            << "Width: " << boundedRectCircle.width << std::endl
            << "Height: " << boundedRectCircle.height << std::endl << std::endl;

  shape = &rectangle1;

  //Демонстрация перемещения фигуры
  //смещение в заданную точку
  shape->move(15, 15);
  std::cout << "After moving 1" << std::endl;
  shape->printInfo();

  //смещение центра
  shape->move(20, 20);
  std::cout << "After moving 2" << std::endl;
  shape->printInfo();

  //Получение ограничивающего прямоугольника для прямоугольника
  const rectangle_t boundedRectRectangle = shape->getFrameRect();
  std::cout << "Bounded rectangle for Rectangle has" << std::endl
            << "X (center): " << boundedRectRectangle.pos.x << std::endl
            << "Y (center): " << boundedRectRectangle.pos.y << std::endl
            << "Width: " << boundedRectRectangle.width << std::endl
            << "Height: " << boundedRectRectangle.height << std::endl;

  return 0;
}
