#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main() {
  Circle c1({2, 3}, 1); // Круг по точке и радиусу
  c1.move(5, 2); // Перемещение по смещению

  Circle c2(4, 7, 2); // Круг по координатам и радиусу

  Rectangle r1({4, 5}, 2, 4); // Прямоугольник по точке и сторонам
  r1.move({2, 2}); // Перемещение по точке

  Rectangle r2({6, 2}, 3); // Прямоугольник по координатам и стороне
  r2.move(2, 5); // Перемещение по смещению

  // Вписываем круг в квадрат
  rectangle_t rect_r2 = r2.getFrameRect();
  Circle c3(rect_r2.pos, rect_r2.width/2);

  // Выводим информацию о фигурах
  Shape * shapes[5] = {&c1, &c2, &c3, &r1, &r2};
  int i = 0;
  for (Shape * shape : shapes) {
    rectangle_t rect_tmp = shape->getFrameRect();
    std::cout << "shapes[" << i << "]\nPos: ("
        << rect_tmp.pos.x << ";" << rect_tmp.pos.y << ")\nDim: "
        << rect_tmp.width << "x" << rect_tmp.height << '\n'
        << "Area: " << shape->getArea() << "\n\n";

    i++;
  }

  return 0;
} // Дальше идет пустая строка. UTF-8. LF.
