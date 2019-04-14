#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printRecData(const chugaynov::rectangle_t &rect)
{
  std::cout << "width = " << rect.width << "\t\theight = " << rect.height
    << "\t\tpos = (" << rect.pos.x << ", " << rect.pos.y << ")" << std::endl;
}

int main()
{
  try 
  {
    chugaynov::point_t pointTest1{ 16.45, 18.4 };
    chugaynov::point_t pointTest2{ 363.5, 478.7 };

    chugaynov::Rectangle rect(pointTest1, 12, 23.4);
    std::cout << "Square before scale = " << rect.getArea() << std::endl;
    rect.move(5, -4);
    printRecData(rect.getFrameRect());
    rect.move(pointTest2);
    printRecData(rect.getFrameRect());
    rect.scale(2);
    printRecData(rect.getFrameRect());
    std::cout << "Square after scale = " << rect.getArea() << std::endl;

    chugaynov::Circle circ(pointTest2, 5.54);
    std::cout << "\nSquare before scale = " << circ.getArea() << std::endl;
    circ.move(5.9, -3.5);
    printRecData(circ.getFrameRect());
    circ.move(pointTest2);
    printRecData(circ.getFrameRect());
    circ.scale(2);
    printRecData(circ.getFrameRect());
    std::cout << "Square after scale = " << circ.getArea() << std::endl;

    std::cout << "\n\npolymorphism:" << std::endl;

    chugaynov::Shape *shape = &rect;
    std::cout << "Square before scale = " << shape->getArea() << std::endl;
    std::cout << "S = " << shape->getArea() << std::endl;
    shape->move(75.4, -4.18);
    printRecData(shape->getFrameRect());
    shape->move(pointTest1);
    printRecData(shape->getFrameRect());
    shape->scale(1.2);
    printRecData(shape->getFrameRect());
    std::cout << "Square after scale = " << shape->getArea() << std::endl;

    shape = &circ;
    std::cout << "\nSquare before scale = " << shape->getArea() << std::endl;
    shape->move(0.3, -25.5);
    printRecData(shape->getFrameRect());
    shape->move(pointTest1);
    printRecData(shape->getFrameRect());
    shape->scale(1.2);
    printRecData(shape->getFrameRect());
    std::cout << "Square after scale = " << shape->getArea() << std::endl;
  }
  catch (const std::exception &ex)
  {
    std::cerr << ex.what() << std::endl;
    return 1;
  };
  return 0;
}
