#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  std::cout << "Circle:" << std::endl;
  che::Circle circle({1,1},3);
  che::Shape *figure = &circle;
  figure->Info();
  std::cout << "Scaling by 2: " << std::endl;
  figure->scale(2);
  figure->Info();
  std::cout << "Move circle to point (1, 5)" << std::endl;
  figure->move({ 1, 5});
  figure->Info();
  std::cout << "Circle area = " << figure->getArea() << std::endl;

  std::cout << "Rectangle:" << std::endl;
  che::Rectangle rectangle({2,2,{10,10}});
  che::Shape *figure = &rectangle;
  figure->Info();
  std::cout << "Scaling by 1.5: " << std::endl;
  figure->scale(1.5);
  figure->Info();
  std::cout << "Move Rectangle to point (3, 1)" << std::endl;
  figure->move({ 3, 1});
  figure->Info();
  std::cout << "Rectangle area = " << figure->getArea() << std::endl;

  std::cout << "Triangle:" << std::endl;
  che::Triangle triangle{{4, 8}, {6, 12}, {30, 5}};
  che::Shape *figure = &triangle;
  figure->Info();
  std::cout << "Scaling by 3: " << std::endl;
  figure->scale(3);
  figure->Info();
  std::cout << "Move triangle to point (2, 4)" << std::endl;
  figure->move({ 2, 4 });
  figure->Info();

  return 0;
}
