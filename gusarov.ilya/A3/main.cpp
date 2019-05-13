#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "composite-shape.hpp"

int main()
{
  //прямоугольник
  gusarov::Rectangle rec({2, 3}, 1, 2);
  rec.printInfo();
  std::cout << '\n';
  std::cout << "Area of rectangle is " << rec.getArea() << '\n';
  rec.move(2, 3);
  rec.move({-2, -3});
  rec.scale(2);
  //Вывод данных после смещения и масштабирования
  rec.printInfo();
  std::cout << '\n';
  //окружность
  gusarov::Circle cir({1, 2}, 1);
  cir.printInfo();
  std::cout << '\n';
  std::cout << "Area of circle is " << cir.getArea() << '\n';
  cir.move(2, 1);
  cir.move({4, -3});
  cir.scale(1);
  //Вывод данных после смещения и масштабирования
  cir.printInfo();
  std::cout << '\n';
  //треугольник
  gusarov::Triangle tri({1.0, 0.0}, {2.0, 1.0}, {3.0, 0.0});
  tri.printInfo();
  std::cout << "Area of triangle is " << tri.getArea() << '\n';
  tri.move(2, 3);
  tri.move({-2, -3});
  tri.scale(2);
  //Вывод данных после смещения и масштабирования
  tri.printInfo();
  std::cout << '\n';
  //создание составной фигуры
  gusarov::CompositeShape compShape(rec);
  compShape.add(cir);
  compShape.add(tri);
  std::cout << "Area of composite shape is " << compShape.getArea() << '\n';
  compShape.printInfo();
  std::cout << '\n';
  //сдвиг и масштабирование составной фигуры
  compShape.move(2, 3);
  compShape.scale(3);
  std::cout << "Area of composite shape is " << compShape.getArea() << '\n';
  compShape.printInfo();
  std::cout << '\n';
  //демонстрация удаления элемента составной фигуры
  compShape.remove(0);
  compShape.printInfo();

  return 0;
}
