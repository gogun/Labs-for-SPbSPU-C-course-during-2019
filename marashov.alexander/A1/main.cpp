#include <iostream>
#include <iomanip>
#include "circle.hpp"
#include "rectangle.hpp"

// Вспомогательная функция, позволяющая продемоснтрировать полиморфизм:
// getArea принимает объект типа Shape, но, в зависимости от настоящего типа,
// будет вызван соответствующий метод нахождения площади
double getArea(Shape &shape)
{
  return shape.getArea();
}

int main()
{
  // Создание двух точек с заданными координатами
  const point_t pnt1 = {5, 2}, pnt2 = {-10, 7};

  // Создание кругов и прямоугольников с помощью разных конструкторов:
  // 1) с указанием центра фигуры при помощи координат
  // 2) с указанием центра фигуры при помощи ранее созданной точки
  Circle circle1(0, 0, 5), circle2(pnt1, 10);
  Rectangle rectangle1(-2, -2, 10, 20), rectangle2(pnt2, 40, 80);

  // Демострация перемещения центра фигур:
  // 1) при помощи смещения в заданную точку
  // 2) со смещением прежнего центра на заданные величины
  std::cout << "Now center of circle1 is: "
          << circle1.getCenter().x << "; "
          << circle1.getCenter().y << std::endl;
  point_t newCenter{10.5f, 20.5f};
  circle1.move(newCenter);
  circle2.move(1, 1);
  rectangle1.move({-2, -40});
  rectangle2.move(10, 10);
  std::cout << "Center of circle1 after moving: "
            << circle1.getCenter().x << "; "
            << circle1.getCenter().y << std::endl;

  // Получение ограничивающего прямоугольника для фигур и вывод результата
  const rectangle_t boundedRectCircle1 = circle1.getFrameRect();
  std::cout << std::fixed << std::setprecision(3)
      << "Bounded rectangle for circle1:" << std::endl
      << "Pos X: " << boundedRectCircle1.pos.x << ", "
      << "Pos Y: " << boundedRectCircle1.pos.y << ", "
      << "Width: " << boundedRectCircle1.width << ", "
      << "Height: " << boundedRectCircle1.height << std::endl;

  const rectangle_t boundedRectRectangle2 = rectangle2.getFrameRect();
  std::cout
      << "Bounded rectangle for rectangle1:" << std::endl
      << "Pos X: " << boundedRectRectangle2.pos.x << ", "
      << "Pos Y: " << boundedRectRectangle2.pos.y << ", "
      << "Width: " << boundedRectRectangle2.width << ", "
      << "Height: " << boundedRectRectangle2.height << std::endl;

  // Демострация полиморфизма при помощи вспомогательной функции
  std::cout << "Area of circle1: " << getArea(circle1) << std::endl;
  std::cout << "Area of rectangle1: " << getArea(rectangle1) << std::endl;

  return 0;
}
