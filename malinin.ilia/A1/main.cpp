#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Shape *ptr;

  Circle circle(20.0, {2.0, -3.0});
  Rectangle rectangle(19.0, 7.0, {-15.0, -17.0});

  ptr = &rectangle;

  std::cout << "\nRECTANGLE\n";
  ptr->showInfo();
  std::cout << "\nMove (to new position using point) X: -7.3, Y: 3.7\n";
  ptr->move({-7.3, 3.7});
  ptr->showCords();
  ptr->showFrameRect();

  std::cout << "\n==================================================\n";

  ptr = &circle;
  std::cout << "\nCIRCLE\n";
  ptr->showInfo();
  std::cout << "\nMove (using coordinates) X: -1, Y: -3\n";
  ptr->move(-1.0, 2.0);
  ptr->showCords();
  ptr->showFrameRect();

  return(0);
}
