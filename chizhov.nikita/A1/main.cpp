#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main() {
  Circle * c1 = new Circle({2, 3}, 1); // Круг по точке и радиусу
  c1->move(5, 2); // Перемещение по смещению

  Circle * c2 = new Circle(4, 7, 2); // Круг по координатам и радиусу

  Circle * c3 = new Circle(); // "Нулевой" круг

  Rectangle * r1 = new Rectangle({4, 5}, 2, 4); // Прямоугольник по точке и сторонам
  r1->move({2, 2}); // Перемещение по точке

  Rectangle * r2 = new Rectangle({6, 2}, 3); // Прямоугольник по координатам и стороне
  r2->move(2, 5); // Перемещение по смещению

  // Вписываем "нулевой" круг в квадрат
  rectangle_t rect_r2 = r2->getFrameRect();
  c3->move(rect_r2.pos);

  // Выводим информацию о фигурах
  Shape * shapes[5] = {c1, c2, c3, r1, r2};
  int i = 0;
  for (Shape * shape : shapes) {
    rectangle_t rect_tmp = shape->getFrameRect();
    std::cout << "shapes[" << i << "]\nPos: ("
        << rect_tmp.pos.x << ";" << rect_tmp.pos.y << ")\nDim: "
        << rect_tmp.width << "x" << rect_tmp.height << '\n'
        << "Area: " << shape->getArea() << "\n\n";

    i++;
  }

  // Заведомо некорректная фигура. Выводится ошибка в cerr
  Circle c4  = Circle({0, 5}, -2);
  rectangle_t rect_c4 = c4.getFrameRect();

  std::cout << "shapes[c4]\nPos: ("
            << rect_c4.pos.x << ";" << rect_c4.pos.y << ")\nDim: "
            << rect_c4.width << "x" << rect_c4.height << '\n'
            << "Area: " << c4.getArea() << "\n\n";

  // Чистим хвосты
  for (Shape * shape : shapes) {
    delete(shape);
  }

  return 0;
} // Дальше идет пустая строка. UTF-8. LF.
