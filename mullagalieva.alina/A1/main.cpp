#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Circle circle{point_t{4.12, 6.7}, 3.5};
  Rectangle rectangle{7.65, 3.65, 8.91, 13.01};
  Triangle triangle{point_t{3.17, 8.1}, 3, 4, 5};

  Shape* shapePointer = &circle;
  std::cout << "Circle:" << "\n";
  std::cout << "Area: " << shapePointer->getArea() << "\n";
  std::cout << "Frame Rectangle centre: ("
      << shapePointer->getFrameRect().pos.x << "; "
      << shapePointer->getFrameRect().pos.y << ")" << "\n";
  std::cout << "Frame Rectangle width: "
      << shapePointer->getFrameRect().width << "\n";
  std::cout << "Frame Rectangle height: "
      << shapePointer->getFrameRect().height << "\n";
  std::cout << "Position of the first figure: ("
      << shapePointer->getPos().x << "; "
      << shapePointer->getPos().y << ")" << "\n";
  std::cout << "Moving to the point (1; 2.9)" << "\n";
  shapePointer->move({1, 2.9});
  std::cout << "New position of the first figure: ("
      << shapePointer->getPos().x << "; "
      << shapePointer->getPos().y << ")" << "\n";

  shapePointer = &rectangle;
  std::cout << "Rectangle:" << "\n";
  std::cout << "Area: " << shapePointer->getArea() << "\n";
  std::cout << "Frame Rectangle centre: ("
    << shapePointer->getFrameRect().pos.x << "; "
    << shapePointer->getFrameRect().pos.y << ")" << "\n";
  std::cout << "Frame Rectangle width: "
    << shapePointer->getFrameRect().width << "\n";
  std::cout << "Frame Rectangle height: "
    << shapePointer->getFrameRect().height << "\n";
  std::cout << "Position of the second figure: ("
    << shapePointer->getPos().x << "; "
    << shapePointer->getPos().y << ")" << "\n";
  std::cout << "Moving dx = 3.4, dy = 5.6" << "\n";
  shapePointer->move(3.4, 5.6);
  std::cout << "New position of the second figure: ("
    << shapePointer->getPos().x << "; "
    << shapePointer->getPos().y << ")" << "\n";

  shapePointer = &triangle;
  std::cout << "Triangle:" << "\n";
  std::cout << "Area: " << shapePointer->getArea() << "\n";
  std::cout << "Frame Rectangle centre: ("
    << shapePointer->getFrameRect().pos.x << "; "
    << shapePointer->getFrameRect().pos.y << ")" << "\n";
  std::cout << "Frame Rectangle width: "
    << shapePointer->getFrameRect().width << "\n";
  std::cout << "Frame Rectangle height: "
    << shapePointer->getFrameRect().height << "\n";
  std::cout << "Position of the third figure: ("
    << shapePointer->getPos().x << "; "
    << shapePointer->getPos().y << ")" << "\n";
  std::cout << "Moving to the point (6.12; 7.34)" << "\n";
  shapePointer->move({6.12, 7.34});
  std::cout << "New position of the third figure: ("
    << shapePointer->getPos().x << "; "
    << shapePointer->getPos().y << ")" << "\n";
    
  return 0;
}
