#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Shape *figure;

  Circle circle(20.0, {2.0, -3.0});
  Rectangle rectangle(19.0, 7.0, {-15.0, -17.0});

  figure = &rectangle;

  std::cout << "\nRECTANGLE\n";
  figure->showInfo();
  std::cout << "\nMove (to new position using point) X: -7.3, Y: 3.7\n";
  figure->move({-7.3, 3.7});
  figure->showCords();
  std::cout << "\nMove (using coordinates) X: -3.2, Y: 5.9\n";
  figure->move(-3.2, 5.9);
  figure->showCords();
  figure->showFrameRect();

  std::cout << "\n==================================================\n";

  figure = &circle;
  std::cout << "\nCIRCLE\n";
  figure->showInfo();
  std::cout << "\nMove (to new position using point) X: 5.1, Y: -2.2\n";
  figure->move({5.1, -2.2});
  figure->showCords();
  std::cout << "\nMove (using coordinates) X: -1.0, Y: 2.0\n";
  figure->move(-1.0, 2.0);
  figure->showCords();
  figure->showFrameRect();

  return(0);
}
