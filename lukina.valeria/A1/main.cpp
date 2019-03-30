#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main ()
{
  Rectangle r (10.0, 5.0, {1.0, 2.0});
  std::cout << "Rectangle area: " << r.getArea() << '\n';
  std::cout << "Bounding box options:\n" ;
  std::cout << "Width: " << r.getFrameRect().width << '\n';
  std::cout << "Height: " << r.getFrameRect().height << '\n';
  std::cout << "Center: " <<r.getFrameRect().pos.x << " , " <<  r.getFrameRect().pos.y << '\n';
  r.move ({0.0, 0.0});

  Circle c (3.0, {2.0, 1.0});
  std::cout << "Area of a circle: " << c.getArea() << std::endl;
  std::cout << "Bounding box options:\n" ;
  std::cout << "Width: " << c.getFrameRect().width << '\n';
  std::cout << "Height: " << c.getFrameRect().height << '\n';
  std::cout << "Center: " << c.getFrameRect().pos.x << " , " <<  c.getFrameRect().pos.y << '\n';
  c.move (-2.0, -1.0);

  std::cout << "Polymorphism:\n";
  Shape* figures[2];
  figures[0] = &r;
  figures[1] = &c;
  for (int i = 0; i < 2; i++)
  {
    std::cout << figures[i]->getArea() << std::endl;
  }
  return 0;
};
