#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  senatova::Circle circle({6, -4}, 15.3);
  senatova::Shape * shape = &circle;
  std::cout << "Circle info\n";
  shape -> print();
  std::cout << "Add to OX " << 3 << " and to OY " << 2 << std::endl;
  shape -> move(3, 2);
  shape -> print();
  std::cout << "Move to (" << 29 << ", " << 13 << ")\n";
  shape -> move({29, 13});
  shape -> print();
  shape -> scale(21.4);
  std::cout << "New parameters" << std::endl;
  shape -> print();

  senatova::Rectangle rectangle({3, 6}, 5, 8);
  shape = &rectangle;
  std::cout << "Rectangle info\n";
  shape -> print();
  std::cout << "Add to OX " << 5 << " and to OY " << -3 << std::endl;
  shape -> move(5, -3);
  shape -> print();
  std::cout << "Move to (" << 15 << ", " << 10 << ")\n";
  shape -> move({15, 10});
  shape -> print();
  std::cout << std::endl;
  shape -> scale(11.5);
  std::cout << "New parameters" << std::endl;
  shape -> print();
  return 0;
}
