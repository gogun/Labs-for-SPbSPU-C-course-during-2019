#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Rectangle rectangle({5, 7, {5, 4}});
  Shape *figure = &rectangle;
  std::cout << "\nRECTANGLE:\n";
  figure->draw();
  std::cout << "Moving rectangle Ox -3 and Oy 5\n";
  figure->move(-3, 5);
  figure->draw();
  std::cout << "Moving rectangle to the point (9, 4)\n";
  figure->move({9, 4});
  figure->draw();
  std::cout << "\n";

  Circle circle(7, {1, 5});
  figure = &circle;
  std::cout << "CIRCLE:\n";
  figure->draw();
  std::cout << "Moving circle Ox +4 and Oy +3\n";
  figure->move(4, 3);
  figure->draw();
  std::cout << "Moving circle to the point (-10, 7)\n";
  figure->move({-10, 7});
  figure->draw();
  std::cout << "\n";

  return 0;
}
