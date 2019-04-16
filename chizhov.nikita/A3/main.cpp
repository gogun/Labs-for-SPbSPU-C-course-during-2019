#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

void printInfo(const chizhov::Shape& shape, const char* name = "Shape")
{
  chizhov::rectangle_t rectTmp = shape.getFrameRect();
  std::cout << name << ":\nPos: ("
      << rectTmp.pos.x << ";" << rectTmp.pos.y << ")\nDim: "
      << rectTmp.width << "x" << rectTmp.height << '\n'
      << "Area: " << shape.getArea() << "\n\n";
}

int main()
{
  // c* - от Circle, круг
  // r* - от Rectangle, прямоугольник
  // cs* - от CompositeShape, составная фигура

  chizhov::Circle c1({1, 2}, 1);

  chizhov::Rectangle r1({2, 1}, 2);

  chizhov::CompositeShape cs1(c1);
  cs1.addShape(r1);
  printInfo(cs1, "Composite shape");

  cs1.move(1, 1);
  printInfo(cs1, "Composite shape");

  cs1.scale(2);
  cs1.deleteShape(c1);
  printInfo(cs1, "Composite shape");

  cs1.move({1.5, 1.5});

  chizhov::Circle c2(4, 7, 2);
  c2.scale(1.5);

  chizhov::Rectangle r2({6, 2}, 3);
  r2.move(2, 5);

  chizhov::Rectangle r3(6, 2, 3, 3);
  r3.move(2, 5);

  // Вписываем круг в квадрат
  chizhov::rectangle_t rect_r2 = r2.getFrameRect();
  chizhov::Circle c3(rect_r2.pos, rect_r2.width / 2);

  // Выводим информацию о фигурах
  chizhov::Shape* shapes[] = {&c1, &c2, &c3, &r1, &r2, &r3, &cs1,};
  for (chizhov::Shape * shape : shapes) {
    printInfo(*shape);
  }

  return 0;
}
