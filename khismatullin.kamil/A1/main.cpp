#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main() {
  Rectangle *rectangle = new Rectangle{{2, 4}, 7, 10};  //создание прямоугольника
  std::cout << "[Rectangle]" << std::endl;  //вывод параметров прямоугольника(на следующей строке)
  std::cout << "Center : (" << rectangle->getCenter().x << " , " << rectangle->getCenter().y << ")" << std::endl
      << "Height : " << rectangle->getFrameRect().height << std::endl
      << "Width  : " << rectangle->getFrameRect().width << std::endl
      << "Area   : " << rectangle->getArea() << std::endl;

  std::cout << std::endl << "{Moving}" << std::endl;
  rectangle->move({-3, -3});  //перемещение по координатам и дальнейший вывод текущего положения
  std::cout << "-- to point : (" << rectangle->getCenter().x << " , " << rectangle->getCenter().y << ")" << std::endl;
  rectangle->move(3, 3);  //перемещение по смещению и дальнейший вывод текущего положения
  std::cout << "-- by offset : (" << rectangle->getCenter().x << " , " << rectangle->getCenter().y << ")" << std::endl;
  delete (rectangle);

  std::cout << "___________________________" << std::endl;

  Circle *circle = new Circle{{2, 4}, 5}; //создание круга
  std::cout << "[Circle]" << std::endl; //вывод параметров круга(на следующей строке)
  std::cout << "Center : (" << circle->getCenter().x << " , " << circle->getCenter().y << ")" << std::endl
      << "Radius : " << circle->getRadius() << std::endl
      << "Height of frame rectangle : " << circle->getFrameRect().height << std::endl
      << "Width of frame rectangle  : " << circle->getFrameRect().width << std::endl
      << "Area   : " << circle->getArea() << std::endl;

  std::cout << std::endl << "{Moving}" << std::endl;
  circle->move({3, 3}); //перемещение по координатам и дальнейший вывод текущего положения
  std::cout << "-- to point : (" << circle->getCenter().x << " , " << circle->getCenter().y << ")" << std::endl;
  circle->move(3, 3); //перемещение по смещению и дальнейший вывод текущего положения
  std::cout << "-- by offset : (" << circle->getCenter().x << " , " << circle->getCenter().y << ")" << std::endl;
  delete (circle);

  std::cout << "___________________________" << std::endl;

  return 0;
}
