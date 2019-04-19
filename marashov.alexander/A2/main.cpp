#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  // try для отлова исключений и завершения программы с ненулевым кодом возврата
  try
  {
    // Создание круга и прямоугольника с помощью разных конструкторов:
    // 1) с указанием центра фигуры при помощи координат
    // 2) с указанием центра фигуры при помощи точки
    marashov::Circle circle1(0, 0, 5);
    marashov::Rectangle rectangle1({1, 1}, 10, 20);

    circle1.writeInfo();
    rectangle1.writeInfo();

    // shape указывает на экземпляр круга
    marashov::Shape *shape = &circle1;

    // Демострация перемещения центра круга:
    // 1) при помощи смещения в заданную точку
    shape->move({10, 10});

    std::cout << "After moving: " << std::endl;
    shape->writeInfo();

    // Демонстрация изотропного масштабирования круга
    const double circleAmount = 2;
    const double circleArea = shape->getArea();
    shape->scale(circleAmount);
    std::cout
        << std::fixed << std::setprecision(3)
        << "Previous circle area: " << circleArea << ", "
        << "Area after scaling: " << shape->getArea() << ", "
        << "Change in area was " << shape->getArea() / circleArea << " times"
        << std::endl << std::endl;

    // Получение ограничивающего прямоугольника для круга и вывод результата
    const marashov::rectangle_t boundedRectCircle1 = shape->getFrameRect();
    std::cout
        << "Bounded rectangle for circle1:" << std::endl
        << "Pos X: " << boundedRectCircle1.pos.x << ", "
        << "Pos Y: " << boundedRectCircle1.pos.y << ", "
        << "Width: " << boundedRectCircle1.width << ", "
        << "Height: " << boundedRectCircle1.height
        << std::endl << std::endl;

    // Теперь shape указывает на экземпляр прямоугольника
    shape = &rectangle1;

    // Демострация перемещения центра прямоугольника:
    // со смещением прежнего центра на заданные величины
    shape->move(-100, 0);

    std::cout << "After moving: " << std::endl;
    shape->writeInfo();

    // Демонстрация изотропного масштабирования прямоугольника
    const double rectAmount = 2;
    const double rectArea = shape->getArea();
    shape->scale(rectAmount);
    std::cout
        << "Previous rectangle area: " << rectArea << ", "
        << "Area after scaling: " << shape->getArea() << ", "
        << "Change in area was " << shape->getArea() / rectArea << " times"
        << std::endl << std::endl;

    // Получение ограничивающего прямоугольника для прямоугольника и вывод результата
    const marashov::rectangle_t boundedRectRectangle1 = shape->getFrameRect();
    std::cout
        << "Bounded rectangle for rectangle1:" << std::endl
        << "Pos X: " << boundedRectRectangle1.pos.x << ", "
        << "Pos Y: " << boundedRectRectangle1.pos.y << ", "
        << "Width: " << boundedRectRectangle1.width << ", "
        << "Height: " << boundedRectRectangle1.height
        << std::endl;
  }
  catch(std::invalid_argument & exception)
  {
    std::cerr << exception.what();
    // В случае некорректных аргументов код возврата равен 1
    exit(1);
  }
  return 0;
}
