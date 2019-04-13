#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  pavlova::Circle circle(3, {6, 6});
  std::cout << "Circle:" << "\n";
  std::cout << "Area: " << circle.getArea() << "\n";
  std::cout << "Scaling" << "\n";
  circle.scale(2);
  std::cout << "New area: " << circle.getArea() << "\n";
  std::cout << "\n";

  pavlova::Rectangle rectangle(4, 4, {5, 5});
  std::cout << "Rectangle:" << "\n";
  std::cout << "Area: " << rectangle.getArea() << "\n";
  std::cout << "Scaling" << "\n";
  rectangle.scale(2);
  std::cout << "New area: " << rectangle.getArea() << "\n";

  return 0;
}
