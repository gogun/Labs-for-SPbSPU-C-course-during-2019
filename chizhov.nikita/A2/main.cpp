#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  chizhov::Circle c1({2, 3}, 1); // Круг по точке и радиусу
  c1.move(5, 2); // Перемещение по смещению

  chizhov::Circle c2(4, 7, 2); // Круг по координатам и радиусу
  c2.scale(1.5); // Изменяем масштаб круга в полтора раза

  chizhov::Rectangle r1({4, 5}, 2, 4); // Прямоугольник по точке и сторонам
  r1.move({2, 2}); // Перемещение по точке

  chizhov::Rectangle r2({6, 2}, 3); // Прямоугольник по точке и стороне
  r2.move(2, 5); // Перемещение по смещению

  chizhov::Rectangle r3(6, 2, 3, -3); // Прямоугольник по координатам и сторонам
  r3.move(2, 5); // Перемещение по смещению

  // Вписываем круг в квадрат
  chizhov::rectangle_t rect_r2 = r2.getFrameRect();
  chizhov::Circle c3(rect_r2.pos, rect_r2.width/2);

  // Выводим информацию о фигурах
  chizhov::Shape* shapes[] = {&c1, &c2, &c3, &r1, &r2, &r3,};
  int i = 0;
  for (chizhov::Shape * shape : shapes) {
    chizhov::rectangle_t rect_tmp = shape->getFrameRect();
    std::cout << "shapes[" << i << "]\nPos: ("
        << rect_tmp.pos.x << ";" << rect_tmp.pos.y << ")\nDim: "
        << rect_tmp.width << "x" << rect_tmp.height << '\n'
        << "Area: " << shape->getArea() << "\n\n";

    i++;
  }

  return 0;
}
