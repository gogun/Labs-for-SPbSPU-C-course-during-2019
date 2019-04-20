#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  lysenko::Circle circle(6, {0, 4});
  lysenko::Shape * figure = &circle;
  std::cout << "---CIRCLE:---\n";
  figure->print();
  std::cout << "-Moving circle along Ox +5 and Oy +2\n";
  figure->move(5, 2);
  figure->print();
  std::cout << "-Moving circle to the point (8, 6)\n";
  figure->move({ -8, 6 });
  figure->print();
  std::cout << "-Scaling circle with coefficient 1.8\n";
  figure->scale(2.3);
  figure->print();

  lysenko::Rectangle rectangle({4, 6, {4, 3}});
  figure = &rectangle;
  std::cout << "\n---RECTANGLE:---\n";
  figure-> print();
  std::cout << "-Moving rectangle along Ox +4 and Oy -7\n";
  figure-> move(4, -7);
  figure-> print();
  std::cout << "-Moving rectangle to the point (8, 6)\n";
  figure-> move({8, 6});
  figure-> print();
  std::cout << "-Scaling rectangle with coefficient 2.3\n";
  figure->scale(2.3);
  figure->print();
  std::cout << "\n";

  return 0;
}
