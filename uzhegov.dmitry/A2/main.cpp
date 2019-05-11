#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  uzhegov::Rectangle rec{{0, 0}, 10, 20};
  uzhegov::Shape *shape = &rec;
  std::cout << "PARAMETERS OF THE RECTANGLE:\n";
  shape->printParams();
  shape->move(2, 5);
  std::cout << "PARAMETERS OF THE RECTANGLE AFTER MOVE dx = 2, dy = 5:\n";
  shape->printParams();
  shape->move({-1, -1});
  std::cout << "PARAMETERS OF THE RECTANGLE AFTER MOVE TO (-1, -1):\n";
  shape->printParams();
  shape->scale(2.0);
  std::cout << "PARAMETERS OF THE RECTANGLE AFTER TWOFOLD INCREASE:\n";
  shape->printParams();
      
  uzhegov::Circle circle{{1, 1}, 2};
  shape = &circle;
  std::cout << "PARAMETERS OF THE CIRCLE:\n";
  shape->printParams();
  shape->move(9, 4);
  std::cout << "PARAMETERS OF THE CIRCLE AFTER MOVE dx = 9, dy = 4:\n";
  shape->printParams();
  shape->move({-1, -1});
  std::cout << "PARAMETERS OF THE CIRCLE AFTER MOVE TO (-1, 1):\n";
  shape->printParams();
  shape->scale(3.0);
  std::cout << "PARAMETERS OF THE CIRCLE AFTER THREEFOLD INCREASE:\n";
  shape->printParams();

  return 0;
}
