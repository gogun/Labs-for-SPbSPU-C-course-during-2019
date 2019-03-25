#include <iostream>
#include <iomanip>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  // Создание круга и прямоугольника с помощью разных конструкторов:
  // 1) с указанием центра фигуры при помощи координат
  // 2) с указанием центра фигуры при помощи точки
  Circle circle1(0, 0, 5);
  Rectangle rectangle1({1, 1}, 10, 20);
  circle1.writeInfo();
  rectangle1.writeInfo();

  // Демострация полиморфизма
  Shape * shapeCircle = &circle1;
  Shape * shapeRectangle = &rectangle1;

  // Демострация перемещения центра фигур:
  // 1) при помощи смещения в заданную точку
  // 2) со смещением прежнего центра на заданные величины
  shapeCircle->move({10, 10});
  shapeRectangle->move(-100, 0);

  std::cout << "After moving: " << std::endl;
  shapeCircle->writeInfo();
  shapeRectangle->writeInfo();

  // Получение ограничивающего прямоугольника для фигур и вывод результата
  const rectangle_t boundedRectCircle1 = shapeCircle->getFrameRect();
  std::cout << std::fixed << std::setprecision(3)
      << "Bounded rectangle for circle1:" << std::endl
      << "Pos X: " << boundedRectCircle1.pos.x << ", "
      << "Pos Y: " << boundedRectCircle1.pos.y << ", "
      << "Width: " << boundedRectCircle1.width << ", "
      << "Height: " << boundedRectCircle1.height << std::endl;

  const rectangle_t boundedRectRectangle1 = shapeRectangle->getFrameRect();
  std::cout
      << "Bounded rectangle for rectangle1:" << std::endl
      << "Pos X: " << boundedRectRectangle1.pos.x << ", "
      << "Pos Y: " << boundedRectRectangle1.pos.y << ", "
      << "Width: " << boundedRectRectangle1.width << ", "
      << "Height: " << boundedRectRectangle1.height << std::endl;

  return 0;
}
