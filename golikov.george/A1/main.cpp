#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle mycircle; // создание экземпляра класса "Круг"
  mycircle.m_center = {5.0,5.0}; // инициализация центра окружности
  std::cout << "The center of the circle is: (" << mycircle.m_center.x << ";"
            << mycircle.m_center.y << ")" << '\n';
  mycircle.m_radius = 3.0; // задание её радиуса
  std::cout << "The radius of the circle is: " << mycircle.m_radius << '\n';
  std::cout << "The square of the circle is: " << mycircle.getArea() << '\n';
  Rectangle myrectangle; // создание экземпляра класса "Прямоугольник"
  myrectangle.m_figure = mycircle.getFrameRect();
  // инициализация поля "Фигура" класса "Прямоугольник" ограничивающим окружность прямоугольником

  std::cout << "The square of Frame rectangle is: " << myrectangle.getArea() << '\n';

  std::cout << "Now lets move the center of the circle to a different point" << '\n';
  mycircle.move({10.0, 10.0});
  std::cout << "And now the center of the circle is: (" << mycircle.m_center.x << ";" << mycircle.m_center.y << ")" << '\n';
  return 0;
}
