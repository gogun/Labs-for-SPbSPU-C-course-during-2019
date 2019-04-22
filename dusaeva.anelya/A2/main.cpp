#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  //Rectangle
  dusaeva::Rectangle objRect({5.0, 6.0}, 7.0, 1.0);
  dusaeva::Shape *shape = &objRect;
  
  std::cout << "Rectangle:\n";
  shape->printInfo();
  
  shape->move(5.1, 6.2);
  std::cout << "Coordinate shift:\n";
  shape->printInfo();
  
  shape->move({0.0, 3.0});
  std::cout << "Point shift:\n";
  shape->printInfo();
  
  shape->scale(7.0);
  std::cout << "Scale:\n";
  shape->printInfo();
  
  //Circle
  dusaeva::Circle objCirc({1.0, 5.0}, 6.0);
  shape = &objCirc;
  
  std::cout << "Circle:\n";
  shape->printInfo();
  
  shape->move(1.0, 2.0);
  std::cout << "Coordinate shift:\n";
  shape->printInfo();
  
  shape->move({7.8, -9.0});
  std::cout << "Point shift:\n";
  shape->printInfo();
  
  shape->scale(1.5);
  std::cout << "Scale:\n";
  shape->printInfo();

  //Triangle
  dusaeva::Triangle objTriangle({4.0, 10.0}, {15.0, 6.0}, {1.0, 1.0});
  shape = &objTriangle;
  
  std::cout << "Triangle:\n";
  shape->printInfo();
  
  shape->move(5.4, 7.6);
  std::cout << "Coordinate shift:\n";
  shape->printInfo();
  
  shape->move({1.0, 3.0});
  std::cout << "Point shift:\n";
  shape->printInfo();
  
  shape->scale(1.5);
  std::cout << "Scale:\n";
  shape->printInfo();
  
  shape->scale(1.5);
  std::cout << "Scale:\n";
  shape->printInfo();
  
  return 0;
}
