#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "shape.hpp"

int main() {
  Rectangle rectangle({2, 4}, 7, 10);  //создание прямоугольника
  std::cout << "[Rectangle]" << std::endl;  //вывод параметров прямоугольника(на следующей строке)
  std::cout << "Center : (" << rectangle.getCenter().x << " , " << rectangle.getCenter().y << ")" << std::endl
      << "Height : " << rectangle.getFrameRect().height << std::endl
      << "Width  : " << rectangle.getFrameRect().width << std::endl
      << "Area   : " << rectangle.getArea() << std::endl;

  std::cout << std::endl << "{Moving}" << std::endl;
  rectangle.move({-3, -3});  //перемещение по координатам и дальнейший вывод текущего положения
  std::cout << "-- to point : (" << rectangle.getCenter().x << " , " << rectangle.getCenter().y << ")" << std::endl;
  rectangle.move(5, 2);  //перемещение по смещению и дальнейший вывод текущего положения
  std::cout << "-- by offset : (" << rectangle.getCenter().x << " , " << rectangle.getCenter().y << ")" << std::endl;

  std::cout << "___________________________" << std::endl;

  Circle circle({2, 4}, 5); //создание круга
  std::cout << "[Circle]" << std::endl; //вывод параметров круга(на следующей строке)
  std::cout << "Center : (" << circle.getCenter().x << " , " << circle.getCenter().y << ")" << std::endl
      << "Radius : " << circle.getRadius() << std::endl
      << "Height of frame rectangle : " << circle.getFrameRect().height << std::endl
      << "Width of frame rectangle  : " << circle.getFrameRect().width << std::endl
      << "Area   : " << circle.getArea() << std::endl;

  std::cout << std::endl << "{Moving}" << std::endl;
  circle.move({3, 3}); //перемещение по координатам и дальнейший вывод текущего положения
  std::cout << "-- to point : (" << circle.getCenter().x << " , " << circle.getCenter().y << ")" << std::endl;
  circle.move(3, 3); //перемещение по смещению и дальнейший вывод текущего положения
  std::cout << "-- by offset : (" << circle.getCenter().x << " , " << circle.getCenter().y << ")" << std::endl;

  std::cout << "___________________________" << std::endl;

  Shape *shape[] = {&rectangle, &circle}; //полиморфное применение
  shape[1]->move(5, 10); //перемещение круга сдвигом
  shape[0]->move(6, 7); //перемещение прямоугольника сдвигом
  for (Shape *s:shape) {
    std::cout << "Center : (" << s->getCenter().x << " , " << s->getCenter().y << ")" << std::endl
        << "Height of frame rectangle : " << s->getFrameRect().height << std::endl
        << "Width of frame rectangle  : " << s->getFrameRect().width << std::endl
        << "Area   : " << s->getArea() << std::endl;

    std::cout << "___________________________" << std::endl;
  }


  return 0;
}
