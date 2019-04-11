#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  std::cout << "Circle" << std::endl;
  ustinov::Circle objcircle({2, 2}, 3);
  ustinov::Shape * shp = &objcircle;
  shp->show();
  std::cout << "move Circle at point" << std::endl;
  shp->move({-10, 12});
  shp->show();
  std::cout << "move Circle at the dx, dy" << std::endl;
  shp->move(1, -2);
  shp->show();
  shp->scale(2);
  shp->show();

  std::cout << "Rectangle " << std::endl;
  ustinov::Rectangle objrectangle ({2, 12}, 2, 6);
  shp = &objrectangle;
  shp->show();
  std::cout << "move Rectangle" << std::endl;
  shp->move({-30, -30});
  shp->show();
  std::cout << "move Rectangle" << std::endl;
  shp->move(2, 3);
  shp->show();
  shp->scale(2);
  shp->show();

  return 0;
}
