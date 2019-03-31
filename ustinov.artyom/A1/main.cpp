#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  std::cout << "Circle" << std::endl;
  Circle objcircle(7, 19, 3);
  Shape * shp = &objcircle;
  shp->show();
  std::cout << "move Circle" << std::endl;
  shp->move(-10, 12);
  shp->show();
  std::cout << "move Circle" << std::endl;
  shp->move(1, -2);
  shp->show();
  
  std::cout << "new Rectangle " << std::endl;
  
  Rectangle objrectangle(2, 12, 3, 6);
  shp = &objrectangle;
  shp->show();
  std::cout << "move Rectangle" << std::endl;
  shp->move(-30, -30);
  shp->show();
  std::cout << "move Rectangle" << std::endl;
  shp->move(2, 3);
  shp->show();

  return 0;
}

